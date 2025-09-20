#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    dp.assign(n+1,0);
    vector<int> vec;
    for (int i=0; i<m;i++){
        int num; cin>>num;
        vec.push_back(num);
    }

    //첫 좌석, 1 or 2
    // 두번째 좌석 1 or 2 or 3
    // ... 마지막 좌석 n-1 or n
    //n == 1 1개:
    //n==2 ;
    // 1 2 / 2 1 --> 2개.
    //n == 3;
    // 1 2 3 /1 3 2 / 2 1 3  --> 3 개.
    //n == 4 : 
    // 1 2 3 4 / 1 3 2 4 / 1 2 4 3 / 2 1 3 4 / 2 1 4 3 / --> 5 개

    //1,2,3,5,8,13, ....
    
    // vec 기준으로 나누고, 길이에 맞는 경우의 수를 찾아서 그거끼리 곱함.
    dp[0]=1;
    dp[1]=1;
    for (int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int answer = 1; 
    vector<int> leng;
    int tmp  = 0;
    for (int i=0; i<m; i++){ 
        answer *= dp[vec[i] - tmp - 1];
        tmp = vec[i];
    }
    // 마지막 구간 (VIP가 없어도 포함)
    answer *= dp[n - tmp];

    cout << answer;

}