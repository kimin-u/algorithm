#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct santa{
    int id;
    int r;
    int c; 
    bool status = true;
    int stun = 0;   // turn보다 크면 기절 상태
};

int n,m,p,c,d;
int turn = 0;
vector<vector<int>> graph;
vector<vector<int>> dist; 

pair<int, int> deer;
unordered_map<int, santa> santas;
vector<int> santaidx;

vector<int> answer;

vector<int> di = {-1,0,1,0}; //상우하좌
vector<int> dj = {0,1,0,-1}; 

void crash_deer(int iflag, int jflag){
    //미충돌 시나리오
    if (graph[deer.first][deer.second] == 0) return;

    int idx = graph[deer.first][deer.second];
    
    answer[idx]  += c;

    santa &tmp = santas[idx];
    graph[tmp.r][tmp.c] = 0; //밀려날거니까 0으로 초기화 해주고.
    tmp.r += (iflag * c);
    tmp.c += (jflag * c);

    if (tmp.r <= 0 || tmp.r >n || tmp.c <= 0 || tmp.c > n) {
        //벗어난 경우 
        tmp.status = false;
        return;
    }
    else{
        tmp.stun = turn + 2;
        if (graph[tmp.r][tmp.c] == 0){
            graph[tmp.r][tmp.c] = tmp.id;
        }
        else{
            bool recursivemove = false;
            int ni = tmp.r; 
            int nj = tmp.c;
            int nid = tmp.id;
            while (true){
                recursivemove = false;
                int tmpidx = graph[ni][nj];
                graph[ni][nj] = nid;
                
                if (tmpidx!= 0){
                    recursivemove = true;
                    ni = ni + iflag;
                    nj = nj + jflag;
                    nid = tmpidx;
                    santas[nid].r = ni; santas[nid].c = nj;

                    if (ni <=0 || ni >n || nj <=0 || nj >n ) {
                        //밀려나서 경기장 밖으로 간 경우
                        santas[nid].status = false;
                        recursivemove = false;
                    }
                }

                if (recursivemove == false) break;
            }
        }
    }
}


void crash_santa(int iflag, int jflag, int idx){
    //미충돌 경우
    santa &tmp = santas[idx];

    if (tmp.r != deer.first || tmp.c != deer.second) return;
    
    //충돌 시나리오 
    answer[idx] += d;
    graph[tmp.r][tmp.c] = 0;

    tmp.r += (iflag * d * (-1));
    tmp.c += (jflag * d * (-1));

    if (tmp.r <= 0 || tmp.r >n || tmp.c <= 0 || tmp.c > n) {
        //벗어난 경우 
        tmp.status = false;
        return;
    }
    else{
        tmp.stun = turn + 2;
        if (graph[tmp.r][tmp.c] == 0){
            graph[tmp.r][tmp.c] = tmp.id; //다른 산타랑 충돌 안하는 경우 
        }
        else{
            bool recursivemove = false;
            int ni = tmp.r; 
            int nj = tmp.c;
            int nid = tmp.id;
            while (true){
                recursivemove = false;
                int tmpidx = graph[ni][nj];
                graph[ni][nj] = nid;
                
                if (tmpidx!= 0){
                    recursivemove = true;
                    ni = ni + iflag * (-1);
                    nj = nj + jflag * (-1);
                    nid = tmpidx;
                    santas[nid].r = ni; santas[nid].c = nj;

                    if (ni <=0 || ni >n || nj <=0 || nj >n ) {
                        //밀려나서 경기장 밖으로 간 경우
                        santas[nid].status = false;
                        recursivemove = false;
                    }
                }

                if (recursivemove == false) break;
            }
        }
    }

}

void move_deer(){
    vector<int> dist(santas.size(), 0);

    int ci = deer.first;
    int cj = deer.second;

    int maxval = 1e9;
    int maxi = -1,maxj = -1;
    int maxidx = -1;
    for (int i=0; i<santaidx.size(); i++){
        santa san = santas[santaidx[i]];
        if (san.status == false) continue;

        int tmpmax = ((san.r - ci) * (san.r-ci)) + ((san.c - cj) * (san.c - cj));
        if (tmpmax < maxval){
            maxval = tmpmax;
            maxi = san.r; maxj = san.c;
            maxidx = i;
        }
        else if (tmpmax == maxval){
            if (maxi < san.r){
                maxi = san.r; maxj = san.c;
                maxidx = i;
            }
            else if (maxi == san.r && maxj < san.c){
                maxi = san.r; maxj = san.c;
                maxidx = i;
            }
        }
    }

    int iflag = (maxi > ci) - (maxi < ci);
    int jflag = (maxj > cj) - (maxj < cj);
    
    deer.first += iflag;
    deer.second += jflag;

    crash_deer(iflag, jflag);
}

void move_santa(int idx){
    if (santas[idx].status == false) return;
    if (santas[idx].stun > turn) return;

    santa &tmp = santas[idx];
    int ci = tmp.r, cj = tmp.c;
    int best = (ci-deer.first)*(ci-deer.first) + (cj-deer.second)*(cj-deer.second);
    int bk = -1;
    for (int k = 0; k < 4; k++){            // 상우하좌 순서
        int ni = ci + di[k], nj = cj + dj[k];
        if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
        if (graph[ni][nj] != 0) continue;   // 다른 산타 칸 불가
        int d2 = (ni-deer.first)*(ni-deer.first) + (nj-deer.second)*(nj-deer.second);
        if (d2 < best){ best = d2; bk = k; }   // 현재보다 strictly 가까워야 함
    }
    if (bk == -1) return;

    int ni = ci + di[bk], nj = cj + dj[bk];
    graph[ci][cj] = 0;
    graph[ni][nj] = tmp.id;
    tmp.r = ni; tmp.c = nj;
    crash_santa(di[bk], dj[bk], idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>p>>c>>d;

    answer.assign(p+1,0);
    graph.assign(n+1, vector<int> (n+1, 0));

    cin>>deer.first>>deer.second;
    for (int i=0; i<p; i++){
        santa tmp;
        cin>>tmp.id>>tmp.r>>tmp.c;
        santas[tmp.id] = tmp;
        santaidx.push_back(tmp.id);
        graph[tmp.r][tmp.c] = tmp.id;
    }

    sort(santaidx.begin(), santaidx.end());

    for (int i=0; i<m; i++){
        turn = i + 1;

        bool alive = false;
        for (int id : santaidx) if (santas[id].status) alive = true;
        if (!alive) break;

        //루돌프 움직임
        move_deer();

        //산타 움직임
        for (int idx = 0; idx<santaidx.size(); idx++){
            move_santa(santaidx[idx]);
        }
        for (int id : santaidx) if (santas[id].status) answer[id]++;

    }

    for (int i= 1; i<=p; i++){
        cout<<answer[i]<<" ";
    }

    return 0;
}