#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer=0;
    
    vector<vector<int>> dp;
    int n = s.length();
    dp.assign(n+2, vector<int>(n+2, 0));
    
    for (int i=1; i<=n; i++){
        dp[i][i] =1;
        answer = max(answer, 1);
        if (i!= n && s[i-1] == s[i]){
            dp[i][i+1] = 1;
            answer = max(answer, 2);
        }
    }
    
    for (int i=n; i>=1; i--){
        for (int j=1; j<=n; j++){
            if (s[i-1] == s[j-1] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                answer = max(answer, j-i+1);
            }
        }
    }
    


    return answer;
}