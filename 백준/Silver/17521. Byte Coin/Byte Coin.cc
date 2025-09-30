#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

//올라갈거면 사고, 내려갈거면 팔고
//기울기 바뀌는 지점 알아야 함
ll n,w;
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>w;
    vec.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    bool rise = (vec[1] > vec[0]);
    ll stock=0;
    if (rise){
        stock = w/vec[0];
        w -= (stock * vec[0]);
    }

    for (int i=2; i<n; i++){
        bool tmp = vec[i] > vec[i-1];
        if (rise != tmp){
            if (!tmp){
                w += stock * vec[i-1];
                stock = 0;
                
            }
            else{
                stock = w / vec[i-1];
                w -= (stock * vec[i-1]);
            }
            rise = tmp;

        }
    }
    if (stock!=0){
        w += (stock * vec.back());
    }
    cout<<w;
}