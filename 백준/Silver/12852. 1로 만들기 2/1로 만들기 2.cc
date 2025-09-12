#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp;
vector<int> prv;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(n+1,0);
    prv.assign(n+1,0);

    dp[1]=0;
    for(int i=2;i<=n; i++){
        dp[i] = dp[i-1] + 1;
        prv[i] = i-1;

        if (i%2==0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            prv[i] = i/2;
        }
        if (i%3==0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3]+1;
            prv[i] = i/3;
        }

    }
    vector<int> path;
    for (int cur = n; cur!=0; cur = prv[cur]){
        path.push_back(cur);
    }
    cout<<dp[n]<<'\n';

    for (auto p : path){
        cout<<p<<" ";
    }

}