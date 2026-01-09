#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
    return i<j;
}

int n;
vector<vector<int>> graph;
vector<vector<int>> visited;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int cnt = 0;
vector<int> answer; 

int bfs(int i, int j){
    int area = 1;
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i,j});

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if (graph[ni][nj] == 1 && visited[ni][nj] == 0){
                visited[ni][nj] = 1;
                q.push({ni, nj});
                area++;
            }
        }
    }

    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.assign(n, vector<int>(n,0));
    visited.assign(n, vector<int>(n,0));

    for (int i=0; i<n; i++){
        string str; cin>>str;
        for (int j=0; j<n; j++){
            graph[i][j] = str[j] - '0';
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (graph[i][j] == 1 && visited[i][j] == 0){
                cnt++;
                int tmp = bfs(i,j);
                answer.push_back(tmp);
            }
        }
    }

    sort(answer.begin(), answer.end(), compare);
    
    cout<<cnt<<'\n';
    for (auto a : answer){
        cout<<a<<'\n';
    }
    
}