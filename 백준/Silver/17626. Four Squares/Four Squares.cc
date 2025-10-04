#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(50001,0);
    dp[1]=1;
    for (int i = 2; i<50001; i++){
        dp[i]=i;
        for (int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout<<dp[n];
    
}