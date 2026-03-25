#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;
vector<ll> vec;

bool compare(ll a, ll b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vec.assign(n,0);
    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    int answer = 0;

    sort(vec.begin(), vec.end(), compare);

    for (int k= 0; k<n; k++){
        int left = 0;
        int right = n-1;
        ll val = vec[k];

        while (left < right){
            if (val == vec[left] + vec[right]){
                if (left == k){
                    left++;
                }
                else if (right == k) right--;
                else{
                    answer ++;
                    break;
                }
            }

            else if (val < vec[left] + vec[right]){
                right--;
            }
            else {
                left++;
            }
        }
    }

    cout<<answer;


}