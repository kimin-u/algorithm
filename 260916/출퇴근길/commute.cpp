#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<vector<int>> adj, radj;
int S, T;

vector<int> bfsBlock(int start, int block){
    vector<int> visited(n, 0);
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]){
            if (nxt == block) continue;
            if (!visited[nxt]){
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    return visited;
}

vector<int> bfsPlain(int start, vector<vector<int>>& g){
    vector<int> visited(n, 0);
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for (int nxt : g[cur]){
            if (!visited[nxt]){
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    return visited;
}

int main() {
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(m);
    adj.assign(n, {}); 
    radj.assign(n, {}); 

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second; //start -> end  edges.
        int from = edges[i].first - 1;
        int to = edges[i].second - 1;
        adj[from].push_back(to);
        radj[to].push_back(from);
    }

    cin >> S >> T;
    S--; T--;
    // Please write your code here.

    vector<int> A = bfsBlock(S, T);      // S -> T 안 거치고 도달
    vector<int> B = bfsPlain(T, radj);   // T로 도달 가능 (역방향)
    vector<int> C = bfsBlock(T, S);      // T -> S 안 거치고 도달
    vector<int> D = bfsPlain(S, radj);   // S로 도달 가능 (역방향)

    int answer = 0;
    for (int v = 0; v < n; v++){
        if (v == S || v == T) continue;
        if (A[v] && B[v] && C[v] && D[v]) answer++;
    }

    cout << answer;

    return 0;
}
