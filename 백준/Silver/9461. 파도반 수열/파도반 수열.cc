#include <iostream>
#include <vector>

using namespace std;

int t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    vector<long long> vec(101);
    vec[1]=1;
    vec[2]=1;
    vec[3]=1;
    vec[4]=2;
    vec[5]=2;
    for (int i=6; i<101; i++){
        vec[i] = vec[i-1] + vec[i-5];
    }

    while(t--){
        int n; cin>>n;
        cout<<vec[n]<<'\n';
    }

}