#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, l;
vector<vector<int>> graph;
vector<pair<int, int>> robots;
vector<vector<int>> dist;

vector<int> di = {-1,0,1,0};
vector<int> dj = {0,-1,0,1};

void move_robots(int idx){
    dist.assign(n, vector<int>(n, -1));

    int i = robots[idx].first;
    int j = robots[idx].second;


    queue<pair<int, int>> q;
    q.push({i,j});
    dist[i][j] = 0;

    //내가 있는 지점으로부터 가장 가까운 오염된 격자로 이동한다.
    //bfs를 순서대로 돌리면서 오염된 격자를 만나면 탐색 종료 loop break.

    bool flag = false;
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            
            //못가는 곳.
            if (graph[ni][nj] == -1) continue;

            // ni, nj에 로봇 잇으면 continue;
            bool robot_flag = false;
            for (int r=0; r<robots.size(); r++){
                if (r == idx) continue;
                if (ni == robots[r].first && nj == robots[r].second){
                    robot_flag = true;
                    break;
                }
            }
            if (robot_flag) continue;


            //방문하지 않은곳이면 간다. 그 중에 오염된 격자면 멈추기까지
            if (dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[ci][cj] +1;
            q.push({ni, nj});
        }
    }

    int best = 1e9, bi = -1, bj = -1;
    for (int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            if (dist[a][b] < 0) continue;     // 도달 불가(-1) 또는 시작 칸(0) 제외
            if (graph[a][b] <= 0) continue;    // 오염된 칸만
            if (dist[a][b] < best){            //  작을 때만 갱신
                best = dist[a][b];
                bi = a; bj = b;
            }
        }
    }
    if (bi != -1) robots[idx] = {bi, bj};
}

void cleaning(int idx){
    int i = robots[idx].first;
    int j = robots[idx].second;

    //오른쪽 아래쪽, 왼쪽, 위쪽 방향으로 합을 계산 해 나감.
    int sum_max = -1e9;

    int tmp_sum;
    int direction = -1;
    

    //오른쪽
    tmp_sum= min(20, graph[i][j]);
    for (int k = 0; k<4; k++){
        if (k==1) continue;
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (graph[ni][nj] > 0){
            tmp_sum += min(graph[ni][nj], 20);
        }
    }
    if (sum_max < tmp_sum){
        sum_max = tmp_sum;
        direction = 0;
    }

    //아래쪽
    tmp_sum= min(20, graph[i][j]);
    for (int k = 0; k<4; k++){
        if (k==0) continue;
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (graph[ni][nj] > 0){
            tmp_sum += min(graph[ni][nj], 20);
        }
    }
    if (sum_max < tmp_sum){
        sum_max = tmp_sum;
        direction = 1;
    }

    //왼쪽
    tmp_sum= min(20, graph[i][j]);
    for (int k = 0; k<4; k++){
        if (k==3) continue;
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (graph[ni][nj] > 0){
            tmp_sum += min(graph[ni][nj], 20);
        }
    }
    if (sum_max < tmp_sum){
        sum_max = tmp_sum;
        direction = 2;
    }

    //위쪽
    tmp_sum= min(20, graph[i][j]);
    for (int k = 0; k<4; k++){
        if (k==2) continue;
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (graph[ni][nj] > 0){
            tmp_sum += min(graph[ni][nj], 20);
        }
    }
    if (sum_max < tmp_sum){
        sum_max = tmp_sum;
        direction = 3;
    }

    //direcion 0~3 오른쪽, 아래쪽, 왼쪽 , 위쪽 순서임.
    graph[i][j] = max(graph[i][j]-20, 0);
    int skip_k;
    if (direction ==0) skip_k = 1;
    else if (direction == 1) skip_k =0;
    else if (direction == 2) skip_k = 3;
    else if (direction == 3) skip_k = 2;

    for (int k = 0; k<4; k++){
        if (k == skip_k) continue;
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

        if (graph[ni][nj] > 0){
            graph[ni][nj] = max(0, graph[ni][nj] - 20);
            if (graph[ni][nj] < 0){
                graph[ni][nj] = 0;
            }
        }
    }
}

void accumulation(){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (graph[i][j] > 0){
                graph[i][j] += 5;
            }
        }
    }
}

void diffusion(){
    vector<vector<int>> copygraph(n, vector<int>(n,0));

    //copy
    for (int i=0; i<n; i++){
        for (int j =0; j<n; j++){
            copygraph[i][j] = graph[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (graph[i][j] == 0){
                int tmpsum = 0;
                for (int k=0; k<4; k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

                    if(graph[ni][nj] > 0){
                        tmpsum+=graph[ni][nj];
                    }
                }
                copygraph[i][j] += (tmpsum/10);

            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j =0; j<n; j++){
            graph[i][j] = copygraph[i][j];
        }
    }
}

void printing(){
    int sum=0;
    for (int i=0; i<n; i++){
        for (int j =0; j<n; j++){
            if (graph[i][j] > 0){
                sum += graph[i][j];
            }
        }
    }

    cout<<sum<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //input
    cin>>n>>k>>l;
    graph.assign(n, vector<int>(n, 0));

    //initialize
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    
    for (int i=0; i<k; i++){
        int r, c;
        cin>>r>>c;
        r--; c--;
        robots.push_back({r,c});
    }

    for (int turn =0; turn<l; turn++){
        //simulation start.
        //1. 청소기 이동
        for (int i=0; i<robots.size(); i++){
            move_robots(i);
        }

        //2. 청소
        for (int i =0; i< robots.size(); i++){
            cleaning(i);
        }

        //먼지 축적
        accumulation();

        //먼지 확산
        diffusion();

        //출력
        printing();


    }



    return 0;
}
