#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(n+2,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2]= 1;
    for (int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n];
}