#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> a;
long long b, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    a.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>b>>c;

    long long answer = 0;

    for (int i=0; i<n; i++){
        a[i] -= b;
        answer++;
        if (a[i] <=0) continue;
        answer += a[i]/c;
        if (a[i]%c != 0) answer++;
    }
    cout<<answer;
}
