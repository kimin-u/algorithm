#include <iostream>
#include <vector>

#define MOD 16769023

using namespace std;

vector<int> dp; //dp[i] : 길이 i인 문자열중에 균형문자열 개수
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(n+1,0);

    dp[1] = 2; //0, 1 

    for (int i=2; i<=n; i++){
        if (i%2!=0){
            dp[i] = dp[i-1]*2;
        }
        else dp[i] = dp[i-1];
        dp[i] %= MOD;
    }


    cout<<dp[n];

}