#include <iostream>
#include <vector>

#define MOD 15746

using namespace std;


int n;
vector<int> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(n+1,0);

    //길이가 n일때 만들 수 잇는 수의 개수 
    dp[1]=1;
    dp[2]=2;
    //1
    //00, 11
    // 001, 111, 100
    // 0011, 0000, 1111, 1100, 1001
    for (int i=3; i<=n; i++){
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= MOD;
    }

    cout<<dp[n];

}