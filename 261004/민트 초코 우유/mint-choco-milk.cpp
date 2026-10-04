#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n, t;
vector<vector<string>> food_graph;
vector<vector<int>> belief_graph;
vector<vector<int>> visited;

// represent가 가져야 할 정보 : 좌표, 신앙심, 그룹의 종류
struct represent{
    int i;
    int j;
    string food;
    int belief;
    bool status; 
};

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

bool compare (pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool compare2(represent a, represent b){
    if (a.food.length() == b.food.length()){
        if (a.belief == b.belief && a.i == b.i) return a.j < b.j;
        else if (a.belief == b.belief) return a.i < b.i;
        return a.belief > b.belief;
    }
    return a.food.length() < b.food.length();
}

string add_food(string food1, string food2){
    string ret ="";
    ret += food1;
    ret += food2;


    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}

void increase_belief(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            belief_graph[i][j]++;
        }
    }
}

pair<int, int> bfs(int i, int j){
    queue<pair<int ,int>> q;
    q.push({i,j});
    visited[i][j] = 1;

    string pivot = food_graph[i][j];
    
    vector<pair<int, int>> vec;
    vec.push_back({i,j});
    
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni <0 || ni >=n || nj<0 || nj>=n) continue;

            if (!visited[ni][nj] && food_graph[ni][nj] == pivot){
                visited[ni][nj] = 1;
                q.push({ni, nj});
                vec.push_back({ni, nj});
            }
        }

    }

    //vec에 같은 그룹들 다 담고 마지막에 sort해서 넘기기. return
    sort(vec.begin(), vec.end(), compare);

    //vec안에서 대표자를 찾고
    pair<int, int> represent;
    int maxbelief = -1e9;
    int maxi = -1;
    int maxj = -1;

    for (int idx = 0; idx < vec.size(); idx++){
        int ci = vec[idx].first;
        int cj = vec[idx].second;

        if (maxbelief < belief_graph[ci][cj]){
            maxbelief = belief_graph[ci][cj];
            maxi = ci;
            maxj = cj;
        }
    }
    represent = {maxi, maxj};
    
    //신앙심 변경 코드까지 짜기.
    for (int i=0; i<vec.size(); i++){
        int ci = vec[i].first;
        int cj = vec[i].second;

        if (ci == represent.first && cj == represent.second){
            belief_graph[ci][cj] += (vec.size()-1);
        }
        else{
            belief_graph[ci][cj]--;
        }
    }


    //대표자 좌표만 return 하면 될 거 같은데 .
    return represent;
}

void propagation(vector<represent> represents){
    for (int idx = 0; idx< represents.size(); idx++){
        //첫 함수 호출 --> 방어상태 풀어주기 필요 
        auto &represent = represents[idx];
        represent.status = false;
    }
    
    for (int idx = 0; idx< represents.size(); idx++){
        auto &represent = represents[idx];
        if (represent.status == true) continue; //방어상태. (다른 사람한테 전파 받은 경우)

        int ni = represent.i;
        int nj = represent.j;
        string pivot_food = represent.food;
        int belief = represent.belief;
        int direction = belief%4;

        int want = belief -1;
        belief_graph[ni][nj] =1;

        //전파 시작. 
        while (want > 0){
            ni += di[direction];
            nj += dj[direction];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) break;

            if (food_graph[ni][nj] == pivot_food) continue;

            if (want > belief_graph[ni][nj]){
                //강한 전파
                want -= (belief_graph[ni][nj] + 1);
                belief_graph[ni][nj]++;
                food_graph[ni][nj] = pivot_food;                
            }
            else{
                //약한 전파
                belief_graph[ni][nj] += want;
                want = 0;
                food_graph[ni][nj] = add_food(food_graph[ni][nj], pivot_food);
            }

            //ni, nj가 대표자 중 한명인 지 체크하긴 해야함 ㅇㅇ 
            for (int i=0; i<represents.size(); i++){
                if (i == idx) continue;
                int tmpi = represents[i].i;
                int tmpj = represents[i].j;

                if (tmpi == ni && tmpj == nj){
                    represents[i].status = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    //input 
    cin>>n>>t;
    food_graph.assign(n, vector<string>(n, ""));
    belief_graph.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int> (n,0));

    //initialize
    string tmp;
    for (int i=0; i<n; i++){
        cin>>tmp;
        for (int j=0; j<n; j++){
            food_graph[i][j] = tmp[j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>belief_graph[i][j];
        }
    }

    // //debug.
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cout<<food_graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //simulation
    for (int day = 0; day<t; day++){
        //아침시간
        increase_belief();

        //점심시간
        //그룹 정보를 담을 vector <pair<int, int>>
        //각 그룹별로 대표자 격자점을 담을 vector<pair<int, int>>.
        visited.assign(n, vector<int> (n, 0));
        vector<represent> represents;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (!visited[i][j]){                    
                    pair<int, int> repre = bfs(i,j);

                    represent tmp;
                    tmp.i = repre.first;
                    tmp.j = repre.second;
                    tmp.belief = belief_graph[tmp.i][tmp.j];
                    tmp.food = food_graph[tmp.i][tmp.j];
                    tmp.status = false;
                    represents.push_back(tmp);
                }
            }
        }

        //저녁시간
        //단일음식 , 이중 조합, 삼중 조합 순서대로 전파 수행. -> represent가 가져야 할 정보 : 좌표, 신앙심, 그룹의 종류
        //전파 순서를 정하기 위한 sorting
        sort(represents.begin(), represents.end(), compare2);

        propagation(represents);


        //printing;
        vector<int> answer(7, 0);
        for (int i=0; i<n; i++){
            for (int j =0; j<n; j++){
                int b = belief_graph[i][j];
                if (food_graph[i][j] == "CMT"){
                    answer[0]+=b;
                }
                else if (food_graph[i][j] == "CT"){
                    answer[1]+=b;
                }
                else if (food_graph[i][j] == "MT"){
                    answer[2]+=b;
                }
                else if (food_graph[i][j] == "CM"){
                    answer[3]+=b;
                }
                else if (food_graph[i][j] == "M"){
                    answer[4]+=b;
                }
                else if (food_graph[i][j] == "C"){
                    answer[5]+=b;
                }
                else if (food_graph[i][j] == "T"){
                    answer[6]+=b;
                }
                
            }
        }

        for (auto &a: answer){
            cout<<a<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}