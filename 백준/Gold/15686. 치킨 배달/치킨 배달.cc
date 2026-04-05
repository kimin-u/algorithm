#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n,m;
vector<vector<int>> graph;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int cnt =0; 
vector<int> remain;
int answer = 1e9;

int get_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int i, vector<int> remain){
    if (remain.size() == m){
        int total = 0;
        for (int i=0; i<house.size(); i++){
            auto p = house[i];
            int min_dist = 1e9;
            for (auto r: remain){
                min_dist = min(min_dist, get_distance(p,chicken[r]));
            }
            total += min_dist;

        }
        answer= min(answer, total);
        return ;

    }

    for (int idx = i; idx<chicken.size(); idx++){
        remain.push_back(idx);
        dfs(idx+1, remain);
        remain.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(n,0));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>graph[i][j];
            if (graph[i][j] == 1){
                house.push_back({i,j});
            }
            else if (graph[i][j] == 2) {
                chicken.push_back({i,j});
            }
        }
    }


    dfs(0, remain);
    cout<<answer;


}