#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <array>

typedef long long ll;
// #define DEBUG

using namespace std;

int q, n;

vector<vector<array<int,4>>> graph; // N x N x 4 (상 우 하 좌)
unordered_map<string, int> umap;
unordered_map<string, ll> needcnt;

vector<string> mapper(string str){
    vector<string> vec;
    
    for (int i=0; i<4; i++){
        //4번 반복.
        //i번째 str[i]부터 시작해서 4글자를 순회해야함.
        string tmp = "";
        tmp += str[i];
        for (int j=0; j<3; j++){
            tmp += str[(i+j+1)%4];
        }
        vec.push_back(tmp);
    }

    

    return vec;
}

void add_spare(string str){
    vector<string> vec = mapper(str);

    //여기서 vec에 들어있는 정보 중 중복 정보를 제거해야함. set을 사용하자 .
    //s.erase(unique(s.begin(),s.end()),s.end());
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    #ifdef DEBUG
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<'\n';
    }
    cout<<'\n';
    #endif
    
    for (auto &s : vec){
        umap[s]++;
    }
}


string get_need(int y, int x){
    if (graph[y][x][0] != 9) return "";

    string need = "";
    //상
    if (y-1<0){
        need += '1';
    }else{
        int tmp = graph[y-1][x][2];
        if (tmp == 0) need +='2';
        else if (tmp==1) need +='1';
        else if (tmp==2) need +='0';
    }
    //우
    if (x+1 >=n){
        need += '1';
    }
    else{
        int tmp = graph[y][x+1][3];
        if (tmp == 0) need +='2';
        else if (tmp==1) need +='1';
        else if (tmp==2) need +='0';
    }
    //하
    if (y+1 >= n){
        need += '1';
    }
    else {
        int tmp = graph[y+1][x][0];
        if (tmp == 0) need +='2';
        else if (tmp==1) need +='1';
        else if (tmp==2) need +='0';
    }
    //좌
    if (x-1 < 0){
        need += '1';
    }
    else{
        int tmp = graph[y][x-1][1];
        if (tmp == 0) need +='2';
        else if (tmp==1) need +='1';
        else if (tmp==2) need +='0';
    }
    return need;
}

void update_around(int y, int x, int delta){
    int dy[5] = {0, -1, 0, 1, 0};
    int dx[5] = {0, 0, 1, 0, -1};
    for (int k=0; k<5; k++){
        int ny = y + dy[k], nx = x + dx[k];
        if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
        string need = get_need(ny, nx);
        if (need != "") needcnt[need] += delta;
    }
}


ll calculate(){
    ll answer = 0;
    for (auto &p : needcnt){
        auto it = umap.find(p.first);
        if (it != umap.end()) answer += p.second * it->second;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;
    int op;
    while (q--){
        cin>>op;
        if (op == 100){
            cin>>n;
            graph.assign(n, vector<array<int,4>>(n, {9,9,9,9}));
        }
        else if (op == 200){
            int y, x, u, r, d, l;
            cin>>y>>x>>u>>r>>d>>l;
            y--; x--;
            update_around(y, x, -1);   // [추가]
            graph[y][x] = {u,r,d,l};
            update_around(y, x, +1);   // [추가]
        }
        else if (op == 300){
            int y, x; cin>>y>>x; y--;x--;
            update_around(y, x, -1);   // [추가]
            graph[y][x] = {9,9,9,9};
            update_around(y, x, +1);   // [추가]
        }
        else if (op == 400){
            //스페어 퍼즐 추가.
            int u,r,d,l;
            cin>>u>>r>>d>>l;

            //unordered_map<string, int> umap; //문자열 - count
            //문자열 정보는 helper function 으로 mapping 필요 
            //helper로 4개 정보를 모두 count 하면 되네.
            string str = to_string(u) + to_string(r) + to_string(d) + to_string(l);
            add_spare(str);
        }
        else if (op == 500){
            //퍼즐 맞추기 : 점수 계산 및 출력.
            ll answer = calculate();
            cout<<answer<<'\n';
            

        }
    }
    return 0;
}