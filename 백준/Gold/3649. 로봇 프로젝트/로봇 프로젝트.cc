#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int x,n,l;
bool compare(int a, int b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin>>x){
        //a + b = x;
        cin>>n;
        vector<int> vec(n);
        for (int i=0; i<n; i++){
            cin>>vec[i];
        }
        sort(vec.begin(), vec.end(), compare);

        ll target = (ll)x*10000000;
        int l = 0 ;
        int r = n-1;

        int a=0, b=0;
        bool found = false;
        while (l<r){
            ll sum = (ll) vec[l] + vec[r];
            if (sum == target){
                a= vec[l];
                b= vec[r];
                found = true;
                break;
            }
            else if (sum < target){
                l++;
            }
            else r--;
        }

        if (found) cout<<"yes "<<a<<" "<<b<<'\n';
        else cout<<"danger\n";
    }
}