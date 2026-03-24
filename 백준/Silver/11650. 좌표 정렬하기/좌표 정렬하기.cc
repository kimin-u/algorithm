#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> vec;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        vec.push_back({x,y});
    }

    sort(vec.begin(), vec.end(), compare);

    for(auto v: vec){
        cout<<v.first<<" "<<v.second<<"\n";
    }

}