#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> colors;
vector<vector<int>> visited;

int answer = 0; 
vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int bfs(int i, int j, vector<vector<int>> &graph){
    visited.assign(3*N, vector<int>(N, 0));
    visited[i][j] = 1;
    

    queue<pair<int, int>> q;
    q.push({i,j});

    vector<pair<int, int>> removedvec;

    int mini, minj;
    int maxi, maxj;

    mini = i; minj = j; maxi = i; maxj = j;
    int cnt =0;
    bool flag = false;
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 2*N || ni >= 3*N || nj < 0 || nj >= N) continue;

            if (!visited[ni][nj] && graph[ci][cj] == graph[ni][nj]){
                visited[ni][nj] = 1;
                q.push({ni,nj});
                mini = min(mini, ni);
                minj = min(minj, nj);
                maxi = max(maxi, ni);
                maxj = max(maxj, nj);
                cnt++;
                flag = true;
                removedvec.push_back({ni,nj});
            }
        }
    }

    if (flag) {
        cnt++;
        removedvec.push_back({i,j});
    }
    else{
        return 0;
    }

    int score = 0;

    score += cnt;

    int wid = maxj-minj+1;
    int len = maxi-mini+1;

    score+= (len*wid);

    //mini, minj, maxi, maxj 기반으로 graph 수정하기. 
    //removedvec 기반으로 그래프 아래로 당기기 
    sort(removedvec.begin(), removedvec.end());
    for (int idx = 0; idx < removedvec.size(); idx++){
        int ci = removedvec[idx].first;
        int cj = removedvec[idx].second;

        for (int pullidx = ci - 1; pullidx >= 0 ; pullidx--){
            graph[pullidx+1][cj]  = graph[pullidx][cj];
        }
    }
    

    // cout<<"BLOCK COUNT : "<<cnt<<'\n';
    // cout<<"AREA : "<< wid*len<<'\n';

    return score;

}

vector<pair<int,int>> getCandidates(vector<vector<int>> &graph){
    vector<vector<int>> seen(3*N, vector<int>(N, 0));
    vector<pair<int,int>> result;
    bool addedNoop = false;

    for (int i = 2*N; i < 3*N; i++){
        for (int j = 0; j < N; j++){
            if (seen[i][j]) continue;

            vector<pair<int,int>> comp;
            queue<pair<int,int>> q;
            q.push({i,j});
            seen[i][j] = 1;

            while (!q.empty()){
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                comp.push_back({ci,cj});

                for (int k=0; k<4; k++){
                    int ni = ci + di[k];
                    int nj = cj + dj[k];
                    if (ni < 2*N || ni >= 3*N || nj < 0 || nj >= N) continue;
                    if (!seen[ni][nj] && graph[ci][cj] == graph[ni][nj]){
                        seen[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }

            if ((int)comp.size() >= 2){
                result.push_back(comp[0]);
            }
            else if (!addedNoop){
                result.push_back(comp[0]);
                addedNoop = true;
            }
        }
    }

    return result;
}

void dfs(int cnt, vector<vector<int>> graph, int curscore){
    if (cnt == 3){
        answer = max(answer, curscore);
        return;
    }

    vector<pair<int,int>> candidates = getCandidates(graph);

    for(auto &c: candidates){
        vector<vector<int>> copygraph = graph;

        int score = bfs(c.first, c.second, copygraph);

        dfs(cnt+1, copygraph, curscore + score);
    
    }
}


int main() {
    cin >> N;

    colors.resize(3 * N, vector<int>(N));
    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> colors[i][j];
        }
    }

    // Please write your code here.

    dfs(0, colors, 0);

    cout<<answer;
    return 0;
}
