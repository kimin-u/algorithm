#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct golem{
    int id;
    int r;
    int c;
    int d; //0, 1, 2, 3 = 북 동 남 서 
    int ei = 0;
    int ej = 0;
};

//helper function.
void calc_golem_exit (golem &a){ //calculate end of golem grids.
    if (a.d == 0){  //북
        a.ei = a.r-1;
        a.ej = a.c;
    }
    else if (a.d == 1){ //동
        a.ei = a.r;
        a.ej = a.c + 1;
    }
    else if (a.d == 2){ //남
        a.ei = a.r + 1;
        a.ej = a.c;
    }
    else if (a.d == 3){  //서
        a.ei = a.r;
        a.ej = a.c - 1;
    }
}

vector<int> di = {-1,0,1,0}; //북 동 남 서
vector<int> dj = {0,1,0,-1};

int r, c, k;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<golem> golems;
int answer = 0;

bool check(int i, int j){ //i,j 기준으로 4방위가 범위를 벗어나지 않는지. 이동 가능한지 . 
    // (i-1,j), (i, j-1), (i, j), (i, j+1), (i+1, j) 가 범위에 벗어나진 않는지, 이동 가능한지 확인하기
    if (i-1 < 0 || i+1 > r+2 || j-1 < 1 || j+1 > c) return false;

    if (graph[i-1][j]!=0 || graph[i][j-1] != 0 || graph[i][j] != 0 || graph[i][j+1] != 0 || graph[i+1][j] != 0) return false;
    return true;
}

bool checkfinal(int i, int j){ //i j 범위 안벗어나면 true. 
    // (i-1,j), (i, j-1), (i, j), (i, j+1), (i+1, j) 가 범위에 벗어나진 않는지, 이동 가능한지 확인하기
    if (i-1 < 3 || i+1 > r+2 || j-1 < 1 || j+1 > c) return false;
    return true;
}

void fix(golem tmp){
    //tmp.r 중심 점 기준으로 좌우상하 1로 만들기. graph확정. 
    graph[tmp.r][tmp.c] = tmp.id;
    graph[tmp.r-1][tmp.c] = tmp.id;
    graph[tmp.r][tmp.c-1] = tmp.id;
    graph[tmp.r][tmp.c+1] = tmp.id;
    graph[tmp.r+1][tmp.c] = tmp.id;
    
    //출구는 2로 갱신
    // graph[tmp.ei][tmp.ej] = 2;
}

void calc_answer(int idx){
    //i=0; i<idx까지 순회하면서 golems들과 출구가 인접한지 
    //일단 각 golem struct마다 최하단 지점이 어딘지를 저장해야할듯? 

    // {tmp.ei, tmp.ej}에서 다른 golem으로 움직일 수 잇는지 확인? 
    // 움직일 수 있음 -> 최댓값 갱신이 가능한지?
    visited.assign(r+3, vector<int> (c+2, 0));
    golem tmp = golems[idx];
    queue<pair<int, int>> q;
    q.push({tmp.r, tmp.c});
    visited[tmp.r][tmp.c] = 1;

    int tmpmax = -1e9;

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        if (tmpmax < ci){
            tmpmax = ci;
        }
        //graph[ci][cj] 가 2인 경우 -> 다른 골렘으로 이동 가능.
        //graph[ci][cj] 가 1인 경우 -> 해당 골렘 내부로만 이동 가능. 
        for (int k =0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni <= 2 || ni > r+2 || nj < 1 || nj > c) continue;

            if (graph[ni][nj] == 0) continue;

            if (!visited[ni][nj]){
                //2냐 아니냐가 아니라 graph[ci][cj]에서 idx 알아내고~
                //golem[idx].ei == ci && golem[idx].ej == cj 라면 다른 칸으로도 이동 가능하다. 
                bool tmpflag = false;
                int tmpidx = graph[ci][cj] -1;
                if (golems[tmpidx].ei == ci && golems[tmpidx].ej == cj) tmpflag = true;

                if (tmpflag){
                    //어디든 이동 가능
                    visited[ni][nj] = 1;
                    q.push({ni, nj});
                }
                else{
                    //다음 graph[ni][nj] 가 현재 있는 칸이랑 같은 골렘인지 파악해야함. //아니면 이동 불가능.
                    if (graph[ni][nj] == graph[ci][cj]){
                        visited[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }

    answer += tmpmax -2;
}

void move(int idx){
    golem &tmp = golems[idx];

    int ci = tmp.r;
    int cj = tmp.c;
    int d = tmp.d;

    int ni, nj;


    while (true){
        if (ci==r+1) break; //남쪽에 닿은 경우.
        //일단 최대한 남쪽으로 이동 -> 반복 (이동 성공했으면 밑에 수행 안하고 continue)
        ni = ci + 1;
        nj = cj;
        
        bool movepossible = false;
        movepossible = check(ni, nj);
        if (movepossible){
            ci = ni;
            cj = nj;
            continue;
        }

        //언제까지 이동해? 남쪽에 닿을 때 까지 

        //서쪽에 자리있는지 확인하고 한칸 이동 -> 다시 loop로  남쪽 방향 이동
        
        if (check(ci, cj-1) && check(ci+1, cj-1)){
            ci += 1;
            cj -= 1;
            //서쪽 이동은 출구가 반시계 방향으로 이동해야함 .
            d = (d+3)%4;        
            continue;
        }        

        //서쪽에 자리 없어? 그럼 동쪽으로 한칸 이동하고 다시 loop로 남쪽방향 이동.
        if (check(ci, cj+1) && check(ci+1, cj+1)) {
            cj += 1; ci += 1;
            d = (d+1)%4;
            continue;
        }

        //여기까지 돌렸는데도 못움직였다? 그럼 더이상 못움직이는 거임. -> graph에 반영해야함 
        break;
    }
    
    //TODO;
    //이제 graph에 반영해야함 움직인 결과를 
    //대신 그래프 영역 위로 튀어나온게 있다면 그건 싹다 날려보내야 함.
    bool confirmflag = checkfinal(ci, cj);
    if (confirmflag == false){
        //clear
        for (int i=0; i<=r+2; i++){
            for (int j=0; j<=c+1; j++){
                graph[i][j] = 0;
            }
        } 
    }
    //graph 반영과 answer 계산하는 수식도 필요함.
    if (confirmflag == true){
        //graph에 반영하고 answer 계산하기 
        tmp.r= ci;
        tmp.c= cj;
        tmp.d = d;
        calc_golem_exit(tmp);
        
        //graph 1로 채우기. 
        fix(tmp); //graph 반영

        //answer 계산해서 더해가기 (출구가 겹치는지도 확인해야함. )
        calc_answer(idx);

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>r>>c>>k;
    graph.assign(r+3, vector<int> (c+2, 0));

    for (int i =0; i<k; i++){
        int gc, gd; cin>>gc>>gd;
        golem tmp;
        tmp.id = i+1; tmp.r = 1; tmp.c = gc; tmp.d = gd;
        calc_golem_exit(tmp);
        golems.push_back(tmp);
    }

    for (int idx = 0; idx < golems.size(); idx++){
        move(idx);
    }


    cout<<answer;
    


    return 0;
}