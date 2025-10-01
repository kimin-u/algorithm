#include <iostream>
#include <vector>

using namespace std;

int a,b,n,w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>a>>b>>n>>w;

    int x,y;
    //x+y = n
    //ax + by = w;

    vector<pair<int, int>> vec;
    for (int i=1; i<=n; i++){
        //i : 염소 x 
        x=i;
        y=n-x;
        if (y<1) continue;
        int tmp  = a*x + b*y;
        if (tmp == w){
            vec.push_back({x,y});
        }
    }

    if (vec.size()>=2 || vec.empty()){
        cout<<-1;
        return 0;
    }
    cout<<vec[0].first<<" " <<vec[0].second;


}