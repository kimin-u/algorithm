#include <string>
#include <vector>

#define MOD 1000000007;

using namespace std;

vector<vector<int>> dp;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp.assign(m+1, vector<int>(n+1,0)); //dp[i][j] : (1,1) ~ (i,j) 까지의 최단 경로의 개수 
    dp[1][1] = 1;
    
    for(int i = 1; i<m+1; i++){
        for (int j = 1; j<n+1; j++){
            if (i==1 && j == 1) continue;
            
            // (i,j)가 물인지 판별해야함. 
            int flag = 0;
            for (auto &puddle : puddles){
                int ti = puddle[0];
                int tj = puddle[1];
                if (i==ti && j== tj){
                    flag=1;
                    break;
                }
            }
            if (flag){
                continue;
            }
            
            if (i==1) {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            if (j==1){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            
            dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % MOD;
        }
    }
    answer = dp[m][n];
    return answer;
}