#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,k;
int answer = 0;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};
vector<int> ans;
int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    visited[i][j] = 1;
    int area = 1; 
    while(!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (ni < 0 || ni >=m || nj<0 ||nj>=n) continue;
            if (graph[ni][nj] == 0 && visited[ni][nj] == 0){
                visited[ni][nj] = 1;
                q.push({ni,nj});
                area++;
            }
        }
    }

    return area;
}

bool compare(int a, int b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>m>>n>>k;
    graph.assign(m, vector<int>(n,0));
    visited.assign(m,vector<int>(n,0));

    for (int i=0; i<k; i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        // graph[x][y] : x -> m-d ~ m-b 까지
        // graph[x][y] : y -> a ~ c 까지    
        for (int x=m-d; x<m-b; x++){
            for (int y=a; y<c; y++){
                graph[x][y] = 1;
            }
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (graph[i][j] == 0 && visited[i][j] ==0){
                ans.push_back(bfs(i,j));
                answer++;
            }
        }
    }
    
    cout<<answer<<'\n';
    sort(ans.begin(), ans.end(), compare);
    for (auto a: ans){
        cout<<a<<" ";
    }
}