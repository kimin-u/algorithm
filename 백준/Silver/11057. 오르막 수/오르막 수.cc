#include <iostream>
#include <vector>
#include <string>

#define MOD 10007
using namespace std;

int n;
vector<int> vec;
vector<vector<int>> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    dp.assign(n+1, vector<int>(10));

    for (int j= 0; j<=9; j++){
        dp[1][j] = 1;
    }

    for (int i =2; i<=n; i++){
        for (int j = 0; j<=9; j++){
            if (j==0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }   
    }

    int result =0;
    for (int j=0; j<=9; j++){
        result += dp[n][j];
        result %=MOD;
    }
    cout<<result;
}