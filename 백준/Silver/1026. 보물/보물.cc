#include <iostream>
#include <vector>
#include <algorithm>

bool compare1(int a, int b){
    return a<b;
}
bool compare2(int a, int b){
    return a>b;
}

using namespace std;

int n;
vector<int> a;
vector<int> b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    a.assign(n,0);
    b.assign(n,0);

    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<n; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end(), compare1);
    sort(b.begin(), b.end(), compare2);

    int answer = 0;
    for (int i=0; i<n; i++){
        answer+=(a[i] * b[i]);
    }
    cout<<answer;



}