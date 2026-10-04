#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
vector<ll> vec;
ll jang, one;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vec.assign(n, 0);
    for (int i=0; i<n; i++ ){
        cin>>vec[i];
    }

    cin>>jang>>one;

    ll answer = 0;
    for (int i=0; i<n; i++){
        answer++;

        ll rest = vec[i];
        rest -= jang;

        if (rest <= 0 ) continue;
        answer += (rest+one-1)/one;
        

    }

    cout<<answer;



    return 0;
}