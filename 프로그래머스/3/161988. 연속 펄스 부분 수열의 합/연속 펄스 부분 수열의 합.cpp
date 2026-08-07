#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

vector<ll> dp1; //dp[i] : i에서 끝나는 부분수열들 중 최댓값. 
vector<ll> dpminus1;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int n = sequence.size();
    dp1.assign(n+1, 0);
    dpminus1.assign(n+1, 0);
    
    dp1[0]=sequence[0];
    dpminus1[0] = - sequence[0];
    
    for (int i=1; i<n; i++){
        if (i%2 == 1){
            dp1[i] = max((ll)-sequence[i], dp1[i-1] - sequence[i]);
            dpminus1[i] = max((ll)sequence[i], dpminus1[i-1] + sequence[i]);
        }
        else{
            dp1[i] = max((ll)sequence[i], dp1[i-1] + sequence[i]);
            dpminus1[i] = max((ll)-sequence[i], dpminus1[i-1] - sequence[i]);
        }
    }
    
    vector<ll> sum1(n+1, 0);
    for (int i =0; i<n; i++){
        
    }
    
    ll ans1 = *max_element(dp1.begin(), dp1.end());
    ll ans2 = *max_element(dpminus1.begin(), dpminus1.end());
    
    
    // //debug
    // cout<<"DP1 : ";
    // for (auto &d : dp1){
    //     cout<<d << " ";
    // }
    // cout<<"\nDP2 : ";
    // for (auto &d : dpminus1){
    //     cout<<d<< " ";
    // }
    // cout<<'\n';
    
    
    
    
    answer = max(ans1, ans2);
    
    return answer;
}