#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int>> graph;
vector<vector<int>> dp;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(m,0));
    dp.assign(n, vector<int>(m,0));
    for (int i=0; i<n; i++){
        string str; cin>>str;
        for (int j =0; j<m; j++){
            graph[i][j] = str[j] -'0';
            if (graph[i][j] == 1) dp[i][j] = 1;
        }
    }

    int answer=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (graph[i][j] == 1){
                if (i > 0 && j > 0)
                    dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout<<answer*answer;
}