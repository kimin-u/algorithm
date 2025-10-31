#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> vec;
vector<int> summ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    vec.assign(n, 0);
    summ.assign(n+1, 0);

    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    for (int i=1; i<=n; i++){
        summ[i] = summ[i-1] + vec[i-1];
    }
    vector<int> answer(n-k+1,0);

    for (int i=0; i<=n-k; i++){
        answer[i] = summ[i+k] - summ[i];
    }

    int a = *max_element(answer.begin(), answer.end());

    cout<<a;


}