#include <string>
#include <vector>
#include <algorithm>

#define MODIFY 1000000007

typedef long long ll;

using namespace std;

vector<ll> dp;

int solution(int n, vector<int> money) {
    dp.assign(n+1, 0);
    
    dp[0] =1;
    for (auto &m : money){
        for (int i=m; i<=n; i++){
            dp[i] += dp[i-m];
            dp[i] %= MODIFY;
        }
    }
    
    
    
    int answer = (int)dp[n];
    return answer;
}