#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
vector<int> vec;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    dp.assign(n+1, 1);
    vec.assign(n,0);

    dp[1]=1;
    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (vec[i] < vec[j]){
                dp[j+1] = max(dp[j+1], dp[i+1] + 1);
            }
        }
    }

    cout<<*max_element(dp.begin(), dp.end());
    
}