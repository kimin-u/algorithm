#include <string>
#include <vector>

#define MOD 1234567

typedef long long ll;

using namespace std;

vector<ll> dp;

long long solution(int n) {
    long long answer = 0;
    
    dp.assign(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i=3; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    
    answer = dp[n];
        
    return answer;
}