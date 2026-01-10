#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int n;
vector<ll> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(92,0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<=91; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    cout<<dp[n];
}