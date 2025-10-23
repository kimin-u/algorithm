#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int n, m;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<pair<int, int>> virus;
vector<int> virus_visited;
int zero_cnt = 0;
int answer = 1e9;

void bfs(){
    queue<pair<int, int>> q;
    visited.assign(n, vector<int>(n,-1));
    for (int i=0; i<virus.size(); i++){
        if (virus_visited[i] == 1){
            q.push({virus[i].first, virus[i].second});
            visited[virus[i].first][virus[i].second] = 0;
        }
    }

    int cnt = 0;
    int time =0;
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci +di[k];
            int nj = cj + dj[k];
            if (ni <0 || ni >=n ||nj<0 ||nj>=n) continue;
            if (graph[ni][nj] == 1) continue;

            if (visited[ni][nj] == -1){
                visited[ni][nj] = visited[ci][cj] + 1;
                q.push({ni,nj});
                if (graph[ni][nj] == 0){
                    cnt++;
                    time = max(time, visited[ni][nj]);
                }
            }
        }
    }

    if (cnt == zero_cnt){
        answer = min(answer, time);
    }
    
}

void pick(int k, int cnt){
    if (cnt == m){
        bfs(); 
        return;
    }
    else{
        for (int i=k; i<virus.size(); i++){
            if (!virus_visited[i]){
                virus_visited[i] = 1;
                pick(i+1, cnt+1);
                virus_visited[i] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(n));
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>graph[i][j];
            if (graph[i][j] == 2 ){
                virus.push_back({i,j});
            }
            else if (graph[i][j] == 0) zero_cnt++;
        }
    }

    virus_visited.assign(virus.size()+1, 0);
    pick(0,0);

    if (answer == 1e9) answer = -1;
    cout<<answer;

}