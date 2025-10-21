#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;
vector<int> vec;

bool compare(int a, int b){
    return a<b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    vec.assign(n,0);
    for (int i=0; i<n; i++)
        cin>>vec[i];

    //어떤 수가, 다른 두 수의 합으로 있느냐?
    // 1= 
    sort(vec.begin(), vec.end(), compare);

    int answer = 0;
    
    for (int k=0; k<n; k++){
        int left = 0; 
        int right = n-1;
        ll target = vec[k];

        while (left < right){
            ll sum = vec[left] + vec[right];

            if (sum < target){
                left++;
            }
            else if (sum > target){
                right--;
            }
            else{
                if (left == k) left++;
                else if (right ==k) right--;
                else{
                    answer++;
                    break;
                }
            }
        }
    }

    cout<<answer;
}