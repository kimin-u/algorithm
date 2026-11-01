#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// #define DEBUG

using namespace std;

int n, b;

struct box{
    int id;
    int t; //투입 턴
    int r; //투입 행
    int c; //투입 열
    int w; //가중치 
    int cnt = 0; //연속 이동 못한 횟수 
    int ans = 0; //정답값. 
    bool flag = false;
    bool status = true;
};

struct compare{
    bool operator() (box a, box b){
        return a.t > b.t; //턴이 작은 순서대로 정렬 
    }
};

priority_queue<box, vector<box>, compare> pq;


vector<vector<int>> graph;
vector<vector<int>> boxgraph;
vector<int> di = {1,0,-1,0}; //아래 왼 위 오른
vector<int> dj = {0,-1,0,1}; //아래 왼 위 오른

unordered_map<int, box> umap;

int turn = 1;

bool can_move(int i, int j){
    box &cur = umap[boxgraph[i][j]];
    if (cur.flag == true) return false; //이미 이번 턴에 이동한 박스면 false return .. 
    //i, j에서의 박스가 다음 칸으로 이동이 가능한 지 여부를 판단하는 함수.
    //주의 
    //i, j에서의 박스가 다음 칸으로 이동했을 때 -> 그 칸으로 이동하는 다른 박스가 있는지를 파악해야함. 
    int dir = graph[i][j];
    // dir : 1~4  아래 왼 위 오른
    dir--;

    //이동할 칸 (다음 칸의 정보 확인..)
    int ni = i + di[dir];
    int nj = j + dj[dir];
    // ni, nj 가 내가 도달할 다음 칸이고.. 
    // 그 칸에 박스가 있는지를 판별해야함 우선.. 그 박스도 이동 가능한지 재귀적으로 호출할 것. 
    if (boxgraph[ni][nj] != 0){
        //박스가 이미 있다면.
        if (!can_move(ni, nj)){
            //그 박스가 이동 불가능하면-> 나도 이동 불가능
            return false;
        }
    }
    // 그 칸으로 이동하는 다른 박스가 있는 지를 판별해야함 .
    // ni, nj 기준으로 4방위를 확인해야함 .
    
    for (int k=0; k<4; k++){
        int pi = ni + di[k];
        int pj = nj + dj[k];

        if (pi == i && pj == j) continue;
        if (pi < 1 || pi > n || pj < 1 || pj > n) continue;
        if (boxgraph[pi][pj] == 0) continue;
        //box가 있긴 한데 내쪽으로 오는지를 판별하긴 해야함. k 값에 따라.. 
        if (graph[pi][pj] - 1 != (k+2)%4) continue;
        if (umap[boxgraph[pi][pj]].flag) continue;

        //여기까지 통과했으면 pi pj 에서 오는 박스랑 나랑 무게 비교, id 비교를 해야 함. 
        //나보다 무겁거나, 같은 무게인데 id가 작은 조건을 만족하면 return false 하고 break
        box tmp = umap[boxgraph[pi][pj]];
        if (tmp.w > cur.w) return false;
        else if (tmp.w == cur.w){
            if (tmp.id < cur.id) return false;
        }
    }

    //여기까지 됐으면 박스가 이동 가능한 것임 -> ni, nj로 박스 이동해야함
    boxgraph[i][j] = 0;
    boxgraph[ni][nj] = cur.id;
    cur.cnt = 0;
    cur.flag = true;

    // //근데 ni nj가 적재함인 경우를 처리해야 함. 
    // if (graph[ni][nj] == 9){
    //     //boxgraph에서 지우고, 현재 턴을 정답값으로 기록해
    //     boxgraph[ni][nj] = 0;
    //     cur.ans = turn;
    //     if (cur.status == false) {
    //         cur.ans *= -1;
    //     }
    // }

    return true;
}

void simulation(){

    for (auto &u : umap){
        u.second.flag = false;
    }
    //이동
    //재귀적으로 다음칸의 박스 이동 가능성을 판단.
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (boxgraph[i][j] != 0){
                if (umap[boxgraph[i][j]].flag) continue;
                //boxgraph[i][j]가 0이 아닌 경우 -> id 인 경우임. 
                bool flag = can_move(i, j);  // bool type return 일텐데 handling 이후에 다시 처리할 것. 

                //이동 못하는 경우 ->  연속 횟수 
                if (!flag){
                    umap[boxgraph[i][j]].cnt++;
                    if (umap[boxgraph[i][j]].cnt >=3 ){
                        umap[boxgraph[i][j]].status = false;
                    }
                }
            }
        }
    }

    //적재 및 파손
    for (int i=1; i<=n; i++){
        for (int j =1; j<=n; j++){
            if (graph[i][j] == 9){
                //적재함인경우
                if (boxgraph[i][j] != 0){
                    //해당 박스를 적재해야함 .
                    
                    box &cur = umap[boxgraph[i][j]];
                    boxgraph[i][j] = 0;
                    cur.ans = turn;
                    if (cur.status == false){
                        cur.ans *= -1;
                    }
                }
            }
        }
    }
    
    //투입
    //pq.top() 에서의 box의 t가 현재 time 보다 작거나 같은지를 기준으로 투입 여부 결정. 
    //이후 boxgraph에서의 다른 박스와 겹침 가능성 판단. 
    
    vector<box> vec;

    while (!pq.empty()){
        box tmp = pq.top();
        if (tmp.t > turn) break;

        //아래는 투입 가능한 경우임. 
        if (boxgraph[tmp.r][tmp.c] != 0) {
            //지금 박스는 투입 못하는데 다른 박스는 투입해야할 수 잇음 
            pq.pop();
            vec.push_back(tmp);
            continue;
        }

        boxgraph[tmp.r][tmp.c] = tmp.id;

        pq.pop();
    }

    for (int v =0; v<vec.size(); v++){
        pq.push(vec[v]);
    }
    
}

void debugprint(){
    cout<<"TURN : " <<turn<<'\n';
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout<<boxgraph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solution(){
    while (true){
        simulation();
        
        #ifdef DEBUG
        if (turn <= 20) debugprint();
        cout<<"7th CNT: "<< umap[7].cnt<<"\n\n";
        #endif
        
        turn++;

        if (turn >= 201) break;
    }

    for (int i=1; i<=b; i++){
        cout << umap[i].ans<<" ";

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    //input & initialize
    cin>>n;
    graph.assign(n+1, vector<int>(n+1,0));
    boxgraph.assign(n+1, vector<int>(n+1, 0));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>>graph[i][j];
        }
    }

    cin>>b;
    for (int i=1; i<=b; i++){
        box tmp;
        tmp.id = i;
        cin>>tmp.t>>tmp.r>>tmp.c>>tmp.w;
        umap[tmp.id] = tmp;
        pq.push(tmp);
    }



    //debug
    #ifdef DEBUG
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (graph[i][j] == 1){
                cout<<"V ";
            }
            else if (graph[i][j] == 2){
                cout<<"< ";
            }
            else if (graph[i][j] == 3){
                cout<<"^ ";
            }
            else if (graph[i][j] == 4){
                cout<<"> ";
            }
            else if (graph[i][j] == 9){
                cout<<"■ ";
            }
            else{
                cout<<"□ ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    #endif

    //simulation.
    solution();

    return 0;
}