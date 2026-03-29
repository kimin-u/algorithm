#include <iostream>
#include <vector>

using namespace std;

int t;
int n;
vector<int> coins;
vector<int> dp;

int m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        coins.assign(n,0);
        for (int i=0; i<n; i++){
            cin>>coins[i];
        }

        cin>>m;
        dp.assign(m+1, 0);
        dp[0] = 1;


        for (int j = 0; j < n; j++){
            int coin = coins[j];
            for (int i = coin; i <= m; i++){
                dp[i] += dp[i-coin];
            }
        }


        cout<<dp[m]<<'\n';

    }
}