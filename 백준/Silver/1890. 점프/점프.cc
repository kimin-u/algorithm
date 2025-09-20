#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int n;
vector<vector<ll>> graph;
vector<vector<ll>> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.assign(n, vector<ll>(n));

    for (int i=0; i<n; i++){
        for (int j =0; j<n;j++){
            cin>>graph[i][j];
        }
    }
    dp.assign(n, vector<ll>(n,0));
    dp[0][0] = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int k = graph[i][j];
            if (k==0) continue;
            if (i+k < n)
                dp[i+k][j] += dp[i][j];
            if (j+k < n)
                dp[i][j+k] += dp[i][j];
        }
    }
    cout<<dp[n-1][n-1];
}