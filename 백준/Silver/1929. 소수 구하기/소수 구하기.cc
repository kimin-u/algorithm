#include <iostream>
#include <vector>

using namespace std;

int m,n;
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>m>>n;
    vec.assign(n+1, 1);

    vec[0] = 0;
    vec[1]= 0;
    for (int i=2; i*i <= n; i++){
        if (vec[i]){
            for (int j = i*i; j<=n; j+=i){
                vec[j] = 0;
            }
        }
    }

    for (int i=m; i<=n; i++){
        if (vec[i]){
            cout<<i<<'\n';
        }
    }
}