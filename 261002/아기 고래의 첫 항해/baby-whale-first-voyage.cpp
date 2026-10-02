#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int r, c;
int d; 

vector<vector<int>> graph;
vector<vector<int>> visited;

vector<pair<int, int>> answer;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

void move_to_next(int i, int j, int d);

//helper function;
int trans_direction(int direction, int k){
    int nd ;
    if (direction == 0){ 
        if (k==0) {
            nd = 0;
        }
        else if (k==1){
            nd = 2;
        }
        else if (k==2){
            nd = 3;
        }
        else{
            nd = 1;
        }
    }
    else if (direction == 1){
        if (k==0){
            nd = 1;
        }
        else if (k==1){
            nd = 3;
        }
        else if (k==2){
            nd = 2;
        }
        else {
            nd = 0;
        }
    }
    else if (direction == 2){
        if (k==0){
            nd = 2;
        }
        else if (k==1){
            nd = 1;
        }
        else if (k==2){
            nd = 0;
        }
        else {
            nd = 3;
        }
    }
    else if (direction == 3){
        if (k==0){
            nd = 3;
        }
        else if (k==1){
            nd = 0;
        }
        else if (k==2){
            nd = 1;
        }
        else {
            nd = 2;
        }
    }

    return nd;
}

void adj_bfs(int r, int c, int d){
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = 1;

    answer.push_back({r+1,c+1});

    int direction = d - 1;

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        int flag = 0;

        for (int k = 0; k < 4; k++){
            //direction에 따라 다음 탐색 지점이 달라져야 함. 앞 좌 우 뒤,
            int nd = trans_direction(direction, k);

            int ni = ci + di[nd];
            int nj = cj + dj[nd];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (graph[ni][nj] == 0 && visited[ni][nj]==0){
                flag = 1;
                direction = nd; 
                visited[ni][nj] = 1;
                q.push({ni, nj});
                answer.push_back({ni + 1, nj + 1});
                break;
            }
        }

        if (!flag){
            //주변에 바다가 없는 경우 -> 가장 가까운 바다로 이동
            move_to_next(ci, cj , direction);
        }
    }
}

void move_to_next(int i, int j, int d){
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[i][j] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<> > pq;
    pq.push({0, {i, j}});

    int prio[4] = {2,1,3,0}; // 좌 하 우 상 

    // (i,j) 로부터 모든 점들의 거리를 계산.
    int minvalue = 1e9;
    int mini = 1e9, minj = 1e9;
    while (!pq.empty()){
        int ci = pq.top().second.first;
        int cj = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dist[ci][cj]) continue;

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            
            if (graph[ni][nj] == 0 && dist[ni][nj] > dist[ci][cj] + 1){
                dist[ni][nj] = dist[ci][cj] + 1;
                pq.push({dist[ni][nj], {ni, nj}});

                if (visited[ni][nj] == 0){
                    if (minvalue > dist[ni][nj]){
                        minvalue = dist[ni][nj];
                        mini = ni;
                        minj = nj;
                    }
                    else if (minvalue == dist[ni][nj]){
                        if (mini > ni){
                            mini = ni; minj = nj;
                        }
                        else if (mini == ni && minj > nj){
                            mini = ni; minj = nj;
                        }
                    }
                }   
            }
        }
    }

    //mini, minj 가 이미 visited면 아예 끝내야 함, (-1, -1) return 
    if (mini != 1e9 && minj != 1e9){
        //direction 갱신 필요 ㅇㅇ  좌 하 우 상 순서로 이동함 (i, j) ~ (mini, minj) 이동 시 마지막 이동 방향을 direction에 저장
        vector<vector<int>> dt(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        dt[mini][minj] = 0;
        q.push({mini, minj});
        while (!q.empty()){
            auto [ci, cj] = q.front(); q.pop();
            for (int k = 0; k < 4; k++){
                int ni = ci + di[k], nj = cj + dj[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (graph[ni][nj] != 0 || dt[ni][nj] != -1) continue;
                dt[ni][nj] = dt[ci][cj] + 1;
                q.push({ni, nj});
            }
        }
        int ci = i, cj = j;
        int last_dir = -1;
        while (!(ci == mini && cj == minj)){
            for (int t = 0; t < 4; t++){
                int k = prio[t];
                int ni = ci + di[k], nj = cj + dj[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                if (graph[ni][nj] == 0 && dt[ni][nj] == dt[ci][cj] - 1){
                    ci = ni; cj = nj;
                    last_dir = k;
                    break;
                }
            }
        }

        // answer.push_back({mini + 1, minj + 1});
        adj_bfs(mini, minj, last_dir+1);        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //problem input
    cin>>n;
    cin>>r>>c>>d;

    //graph assign, visited assign & initialize
    graph.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int>(n, 0));

    //graph input
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    //call function bfs.
    r--; c--;
    adj_bfs(r, c, d);

    for (auto &a: answer){
        cout<<a.first<<" " << a.second<<'\n';
    }


    return 0;
}
