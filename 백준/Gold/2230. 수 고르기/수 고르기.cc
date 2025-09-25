#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

bool compare(int a, int b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vector<int> vec(n);
    for (int i=0; i<n; i++){
        cin>>vec[i];
    }
    
    sort(vec.begin(), vec.end(), compare);

    int l=0;
    int r = 0;
    int answer = 2e9;

    while (r<n && l < n){
        int a=  vec[l];
        int b = vec[r];
        int tmp = b-a;

        if (tmp >= m){
            answer = min(answer, tmp);
            l++;
        }
        else {
            r++;
        }
    }

    cout<<answer;

}