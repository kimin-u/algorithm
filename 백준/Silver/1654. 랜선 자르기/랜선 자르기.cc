#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int k,n;
vector<ll> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>k>>n; //k 개 랜선을 같은 길이로 잘라서 n개를 만듦
    vec.assign(k,0);

    for (int i=0; i<k; i++){
        cin>>vec[i];
    }
    //n개 랜선 만드는데, 그때 각 랜선의 최대 길이?
    ll answer = 0 ;

    ll left = 1;
    ll right = *max_element(vec.begin(), vec.end());

    while (left<=right){
        ll mid = (left + right) / 2;
        if (mid <= 0) return 0;
        ll tmp=0;
        for (int i=0; i<k; i++){
            tmp += (vec[i]/mid);
        }

        if (tmp < n)
        {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }

    cout<<answer;

}