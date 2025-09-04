#include <iostream>
#include <vector>

using namespace std;

int n,m;
int x,y,x2,y2;
vector<vector<int>> graph;
vector<vector<int>> dp;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n+1, vector<int>(n+1, 0));
    dp.assign(n+1, vector<int>(n+1, 0));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    
    //dp[i][j] = graph[0][0] ~ graph[i][j]까지의 합.

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] 
                    - dp[i-1][j-1] + graph[i][j];
        }
    }       

    while(m--){
        cin>>x>>y>>x2>>y2;

        int result = dp[x2][y2] 
                   - dp[x-1][y2] 
                   - dp[x2][y-1] 
                   + dp[x-1][y-1];

        cout << result << "\n";   
    }
}