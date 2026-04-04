#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> parent_info;
vector<int> visited;

int answer =0;

void delet(int node){
   //부모 찾아가서 지우기.
    int parent = parent_info[node];
    if (parent != -1) {
        graph[parent].erase(remove(graph[parent].begin(), graph[parent].end(), node), graph[parent].end());
    }
}

void delete_dfs(int node){
    visited[node] = 1;
    delet(node);
    for (int i= 0; i<graph[node].size(); i++){
        int nxt = graph[node][i];
        if (visited[nxt] == 0){
            delete_dfs(nxt);
        }
    }
}

void dfs(int start){
    visited[start] = 1;

    if (graph[start].size() == 0){
        answer++;
        return ;
    }

    for (int i= 0; i<graph[start].size(); i++){
        int nxt = graph[start][i];
        if (visited[nxt] == 0){
            dfs(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int start;

    cin>>n;
    graph.assign(n, vector<int>());
    parent_info.assign(n,0);
    visited.assign(n, 0);    
    for (int i=0; i<n; i++){
        int num; cin>>num;
        parent_info[i] = num;
        if (num == -1) { start = i; continue;}
        graph[num].push_back(i);
    }

    int node;
    cin>>node;

    delete_dfs(node);

    //리프노드 개수 세기
    if (start == node){
        cout<<0;
        return 0;
    }
    visited.assign(n,0);
    dfs(start);

    cout<<answer;

}