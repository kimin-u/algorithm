#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w,h;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<int> di = {-1,1,0,0,-1,-1,1,1};
vector<int> dj = {0,0,-1,1,-1,1,-1,1};

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] =1;

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        for (int k=0; k<8; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if (visited[ni][nj] == 0 && graph[ni][nj]==1){
                visited[ni][nj]=1;
                q.push({ni,nj});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true){
        cin>>w>>h;
        if (w==0 && h==0) return 0;
        graph.assign(h,vector<int>(w));

        for (int i=0; i<h;i++){
            for (int j=0; j<w; j++){
                cin>>graph[i][j];
            }
        }
        visited.assign(h,vector<int>(w,0));

        int answer = 0;
        for (int i=0 ; i<h; i++){
            for(int j=0; j<w; j++){
                if (visited[i][j] == 0 && graph[i][j] == 1){
                    bfs(i,j);
                    answer++;
                }
            }
        }
        cout<<answer<<'\n';
    }

}