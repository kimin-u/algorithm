#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> vec;
bool compare (int a, int b){
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
    sort(vec.begin(), vec.end(), compare);
    cin>>m;
    for (int i=0; i<m; i++){
        int num; cin>>num;
        int left = 0;
        int right = n-1;
        bool found = false;

        while (left <= right){
            int mid = (left+right)/2;
            if (vec[mid] == num){
                found =true;
                break;
            }
            else if (vec[mid] < num){
                left= mid +1;
            }
            else {
                right = mid-1;
            }
        }
        if (found) cout<<"1\n";
        else cout<<"0\n";
    }
}