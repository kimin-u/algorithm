#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<vector<ll>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = triangle.size();
    dp.assign(n, vector<ll>(n, 0));
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        for (int j = 1; j<i; j++){
            int tmp1 = dp[i-1][j-1] + triangle[i][j];
            int tmp2 = dp[i-1][j] + triangle[i][j];
            dp[i][j] = max(tmp1, tmp2);
        }
    }
    
    answer = (int)*max_element(dp[n-1].begin(), dp[n-1].end());
    return answer;
}