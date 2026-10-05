#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int si, sj; //메두사 집
int ei, ej; //공원 위치 정보.
vector<pair<int, int>> warriors;

vector<vector<int>> graph;
vector<vector<int>> warrior_graph;
vector<vector<int>> stone_graph;
vector<vector<int>> visited;

vector<int> di = {-1,1,0,0}; // 상하좌우
vector<int> dj = {0,0,-1,1};

int movecnt =0;
int attackcnt =0;

bool move_snake(){
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    //역추적 방식으로 구현,
    dist[ei][ej] = 0;
    queue<pair<int, int>> q;
    q.push({ei, ej});

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k =0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (graph[ni][nj] == 1) continue;

            if (dist[ni][nj] > dist[ci][cj] + 1){
                dist[ni][nj] = dist[ci][cj] +1;
                q.push({ni, nj});
            }
        }
    }

    if (dist[si][sj] >= 1e9) return false;

    int ci = si;
    int cj = sj;
    
    for (int k=0; k<4; k++){
        int ni = ci + di[k];
        int nj = cj + dj[k];

        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (dist[ni][nj] == dist[ci][cj] -1){
            si = ni;
            sj = nj;

            // ni nj에 용사가 있는 경우를 처리하는 로직 추가 필요. 
            warrior_graph[si][sj] = 0;
            for (auto &w: warriors){
                if (w.first == si && w.second == sj){
                    w.first = -1;
                    w.second = -1;
                }
            }

            break;
        }
    }

    return true;
}

int head_snake(){
    //si, sj에서 상 하 좌 우 순서로 바라봤을 때 시야 안에 전사가 몇명 있는지 찾아서 max 값을 갖는 방향을 바라보도록 구현하기.
    vector<int> count(4, 0);

    //각 방향별로 결과 그래프를 저장해놓고 max값을 찾으면 해당 그래프를 토대로 이후 시뮬레이션 진행
    vector<vector<vector<int>>> result_graph(4, vector<vector<int>>(n, vector<int>(n, 0)));

    //현재 위치에서 각 방향별로 바라봤을대 볼 수 잇는 좌표들을 계산.
    vector<vector<int>> eyegraph;

    int width, tmpcount;
    //윗 방향 
    eyegraph.assign(n, vector<int>(n, 0));
    width = 1;
    tmpcount = 0;
    for (int i=si-1; i>=0; i--){
        //width 는 i 반복문 루프마다 1씩 커질거고 .
        //j 범위는 sj - width ~ sj + width 까지임.
        for (int j = sj-width; j <= sj + width; j++){
            if (j < 0 || j >=n) continue;

            //용사 만나는 경우 체크  (용사가 있는지 , eeyegraph 가 -1이 아닌지) -> tmpcount 증가 하고, 
            //그 뒷부분은 eyegraph를 미리 -1로 만들어서 tmpcount 증가에 영향 없도록 사전조치 취하기.
            if (warrior_graph[i][j] >=1 && eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
                tmpcount += warrior_graph[i][j];
                int ttmp = 1;
                for (int ni = i-1; ni >= 0; ni--){
                    if (j < sj){ //메두사 보다 왼쪽 위에 있는 경우
                        for (int nj = j-ttmp; nj <= j; nj++){
                            if (nj < 0 || nj >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                    else if (j == sj){ //메두사 위쪽에 있었던 경우
                        eyegraph[ni][j] = -1;
                    }
                    else if (j > sj){ //메두사보다 오른쪽 위에 있던 경우
                        for (int nj = j; nj <= j+ ttmp; nj++){
                            if (nj < 0 || nj >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                }
            }
            if (eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
            }
        }
        width++;
    }

    count[0] = tmpcount;
    result_graph[0] = eyegraph;


    //아랫방향
    eyegraph.assign(n, vector<int>(n, 0));
    width = 1;
    tmpcount = 0;
    for (int i=si+1; i<n; i++){
        //width 는 i 반복문 루프마다 1씩 커질거고 .
        //j 범위는 sj - width ~ sj + width 까지임.
        for (int j = sj-width; j <= sj + width; j++){
            if (j < 0 || j >=n) continue;

            //용사 만나는 경우 체크  (용사가 있는지 , eeyegraph 가 -1이 아닌지) -> tmpcount 증가 하고, 
            //그 뒷부분은 eyegraph를 미리 -1로 만들어서 tmpcount 증가에 영향 없도록 사전조치 취하기.
            if (warrior_graph[i][j] >=1 && eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
                tmpcount += warrior_graph[i][j];
                int ttmp = 1;
                
                for (int ni = i+1; ni <n ; ni++){
                    if (j < sj){ //메두사 보다 왼쪽 위에 있는 경우
                        for (int nj = j-ttmp; nj <= j; nj++){
                            if (nj < 0 || nj >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                    else if (j == sj){ //메두사 위쪽에 있었던 경우
                        eyegraph[ni][j] = -1;
                    }
                    else if (j > sj){ //메두사보다 오른쪽 위에 있던 경우
                        for (int nj = j; nj <= j+ ttmp; nj++){
                            if (nj < 0 || nj >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                }
            }
            if (eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
            }
        }
        width++;
    }

    count[1] = tmpcount;
    result_graph[1] = eyegraph;

    //왼쪽 방향.
    eyegraph.assign(n, vector<int>(n, 0));
    width = 1;
    tmpcount = 0;
    for (int j=sj-1; j >= 0; j-- ){
        //width 는 i 반복문 루프마다 1씩 커질거고 .
        //j 범위는 sj - width ~ sj + width 까지임.
        for (int i = si-width; i <= si + width; i++){
            if (i < 0 || i >=n) continue;

            //용사 만나는 경우 체크  (용사가 있는지 , eeyegraph 가 -1이 아닌지) -> tmpcount 증가 하고, 
            //그 뒷부분은 eyegraph를 미리 -1로 만들어서 tmpcount 증가에 영향 없도록 사전조치 취하기.
            if (warrior_graph[i][j] >=1 && eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
                tmpcount += warrior_graph[i][j];
                int ttmp = 1;
                
                for (int nj = j-1; nj >=0 ; nj--){
                    if (i < si){ //메두사 보다 왼쪽 위에 있는 경우
                        for (int ni = i-ttmp; ni <= i; ni++){
                            if (ni < 0 || ni >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                    else if (i == si){ //메두사 위쪽에 있었던 경우
                        eyegraph[i][nj] = -1;
                    }
                    else if (i > si){ //메두사보다 오른쪽 위에 있던 경우
                        for (int ni = i; ni <= i+ ttmp; ni++){
                            if (ni < 0 || ni >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                }
            }
            if (eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
            }

        }
        width++;
    }

    count[2] = tmpcount;
    result_graph[2] = eyegraph;

    //오른쪽 방향.
    eyegraph.assign(n, vector<int>(n, 0));
    width = 1;
    tmpcount = 0;
    for (int j=sj+1; j < n; j++ ){
        //width 는 i 반복문 루프마다 1씩 커질거고 .
        //j 범위는 sj - width ~ sj + width 까지임.
        for (int i = si-width; i <= si + width; i++){
            if (i < 0 || i >=n) continue;

            //용사 만나는 경우 체크  (용사가 있는지 , eeyegraph 가 -1이 아닌지) -> tmpcount 증가 하고, 
            //그 뒷부분은 eyegraph를 미리 -1로 만들어서 tmpcount 증가에 영향 없도록 사전조치 취하기.
            if (warrior_graph[i][j] >=1 && eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
                tmpcount += warrior_graph[i][j];
                int ttmp = 1;
                
                for (int nj = j+1; nj < n ; nj++){
                    if (i < si){ //메두사 보다 왼쪽 위에 있는 경우
                        for (int ni = i-ttmp; ni <= i; ni++){
                            if (ni < 0 || ni >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                    else if (i == si){ //메두사 위쪽에 있었던 경우
                        eyegraph[i][nj] = -1;
                    }
                    else if (i > si){ //메두사보다 오른쪽 위에 있던 경우
                        for (int ni = i; ni <= i+ ttmp; ni++){
                            if (ni < 0 || ni >= n) continue;
                            eyegraph[ni][nj] = -1;
                        }
                        ttmp++;
                    }
                }
            }
            if (eyegraph[i][j] != -1){
                eyegraph[i][j] = 1;
            }

        }
        width++;
    }

    count[3] = tmpcount;
    result_graph[3] = eyegraph;

    int maxval = -1;
    int maxidx = -1;
    for (int i=0; i<count.size(); i++){
        if (maxval < count[i]){
            maxval = count[i];
            maxidx = i;
        }
    }

    stone_graph = result_graph[maxidx];

    return maxval;    
}

void move_war(){
    movecnt = 0;
    attackcnt = 0;

    const int order[2][4] = {{0,1,2,3}, {2,3,0,1}};   // 상하좌우 / 좌우상하

    for (auto &w : warriors){
        int ci = w.first, cj = w.second;
        if (ci == -1) continue;
        if (stone_graph[ci][cj] == 1) continue;        // 석화된 전사는 이동 안 함

        for (int step = 0; step < 2; step++){
            int curd = abs(ci - si) + abs(cj - sj);

            for (int t = 0; t < 4; t++){
                int d = order[step][t];
                int ni = ci + di[d], nj = cj + dj[d];

                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (stone_graph[ni][nj] == 1) continue;                 // 시야 칸 진입 불가
                if (abs(ni - si) + abs(nj - sj) >= curd) continue;      // 거리가 줄어야 함

                warrior_graph[ci][cj]--;
                warrior_graph[ni][nj]++;
                ci = ni; cj = nj;
                movecnt++;
                break;
            }

            if (ci == si && cj == sj){                 // 메두사 칸에 도착하면 공격 후 소멸
                warrior_graph[ci][cj]--;
                attackcnt++;
                ci = cj = -1;
                break;
            }
        }
        w = {ci, cj};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(n,0));
    warrior_graph.assign(n, vector<int> (n, 0));
    warriors.assign(m, {0, 0});

    cin>>si>>sj>>ei>>ej;

    for (int i=0; i<m; i++){
        cin>>warriors[i].first >> warriors[i].second;
        warrior_graph[warriors[i].first][warriors[i].second]++;
    }

    for (int i=0; i<n; i++){
        for (int j = 0 ; j<n; j++){
            cin>>graph[i][j];
        }
    }

    //simulation
    while (true){
        //loop 1번 = 1번의 턴을 의미 
        // 1. 메두사의 이동.
        if (!move_snake()){
            cout<<-1<<'\n';
            break;
        }
        //종료 조건 : 메두사가 공원에 도착하는 턴인지 확인
        if (si == ei && sj == ej){
            cout<<0<<'\n';
            break;
        }

        // 2. 메두사의 시선.
        int stone_count = head_snake();
        
        // 3. 전사들의 이동 및 공격.
        move_war();

        // 출력
        cout<<movecnt<<" "<<stone_count<<" "<<attackcnt<<'\n';

        
    }

    return 0;
}