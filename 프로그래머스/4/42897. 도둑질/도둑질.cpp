#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> dp1;
vector<int> dp2;


int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    
    dp1.assign(n+1,0);
    dp2.assign(n+1,0);
    
    //dp1 : 1번집 터는 케이스
    dp1[0] = money[0];
    dp1[1] = dp1[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for (int i=2; i<n; i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
    
    answer = max(dp1[n-2], dp2[n-1]);
    
    return answer;
}