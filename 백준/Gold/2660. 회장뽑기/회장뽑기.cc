#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> answer;
vector<int> visited;
vector<int> score;
//1점 : 모두와 친구
//2점 : 친구 or 친구의 친구
//3 wja : 친구 or 친구의 친구 or 친구의 친구의 친구
// 4... 5...

void bfs(int s){
    queue<int> q;
    visited[s] = 0;
    q.push(s);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for (int n = 0; n < graph[cur].size(); n++){
            int next = graph[cur][n];
            if (visited[next] == -1){
                q.push(next);
                visited[next] = visited[cur] + 1; 
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.assign(n, vector<int>());
    answer.assign(n,0);
    visited.assign(n,-1);
    score.assign(n,0);
    while (true){
        int a, b; cin>>a>>b;
        if (a==-1 && b==-1) break;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=0; i<n; i++){
        visited.assign(n,-1);
        bfs(i);
        int tmp =0;
        for(auto v: visited){
            tmp = max(tmp,v);
        }
        score[i] = tmp;
    }
    int maxval = *min_element(score.begin(), score.end());
    int maxcnt = count(score.begin(), score.end(), maxval);

    cout<<maxval<<" "<<maxcnt<<'\n';
    vector<int> indices;
    for (int i = 0; i < score.size(); i++) {
        if (score[i] == maxval) {
            indices.push_back(i+1);
        }
    }

    for (auto i : indices){
        cout<<i<<" ";
    }




}