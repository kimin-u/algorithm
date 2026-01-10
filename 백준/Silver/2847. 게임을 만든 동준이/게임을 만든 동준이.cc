#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++){
        int tmp; cin>>tmp;
        vec.push_back(tmp);
    }

    int answer = 0;

    for (int i=n-1; i>0; i--){
        while (vec[i-1] >= vec[i]){
            vec[i-1] --; answer++;
        }
    }

    cout<<answer;
}