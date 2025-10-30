#include <iostream>
#include <algorithm>
#include <vector>

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

    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end(), compare);
    
    int answer = 0;


    for (auto v: vec){
        answer += (v*n);
        n--;    
    }
    cout<<answer;

}