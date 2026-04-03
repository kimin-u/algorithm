#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
int cnt = 0;

int n,m;
int r,c;
int d;

vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, -1, 0, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});
    cnt++;

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        int tmp_cnt = 0; //4번이면 끝. 아래 while문에서
        int flag = 0;
        while (true){
            if (tmp_cnt == 4){
                flag = 1; 
                break;
            }
            tmp_cnt++;
            d = (d+1) % 4;


            int ni = ci + di[d];
            int nj = cj + dj[d];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            if (graph[ni][nj] != 0) continue;
            if (visited[ni][nj] == 0){
                visited[ni][nj] = 1;
                q.push({ni, nj});
                cnt++;
                break;
            }
        }

        if (!flag){ //다음 청소 구역이 있는 경우
            continue;
        }
        else{ //청소 구역 없음. 다시 후진해야함.
            int ni = ci - di[d];
            int nj = cj - dj[d];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) break;
            if (graph[ni][nj] != 0) break;
            q.push({ni, nj});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    cin>>r>>c>>d;
    if (d==1) d = 3;
    else if (d==3) d = 1;

    graph.assign(n, vector<int>(m,0));
    visited.assign(n, vector<int>(m,0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }


    bfs(r, c);

    cout<<cnt;
}