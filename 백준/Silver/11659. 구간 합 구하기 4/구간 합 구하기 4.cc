#include <iostream>
#include <vector>

using namespace std;

int n,m;
int i,j;
vector<int> vec;
vector<int> summ;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vec.assign(n,0);
    summ.assign(n+1,0);
    for (int i=0; i<n; i++){
       cin>>vec[i];
    }

    //i~j번째 까지 수의 합
    for (int i=1; i<=n; i++){
        summ[i] = summ[i-1] + vec[i-1];
    }
    
    for (int k=0; k<m; k++){
        cin>>i>>j;
        cout<<summ[j] - summ[i-1]<<'\n';

    }
}