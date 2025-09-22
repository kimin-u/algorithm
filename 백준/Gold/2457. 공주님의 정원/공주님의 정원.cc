#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool compare(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}

bool leq(pair<int,int> a, pair<int,int> b) {
    return (a.first < b.first) || (a.first == b.first && a.second <= b.second);
}

bool great(pair<int,int> a, pair<int,int> b) {
    return (a.first > b.first) || (a.first == b.first && a.second > b.second);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vector<pair<pair<int,int>, pair<int,int>>> vec;
    for(int i=0; i<n; i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        vec.push_back({{a,b},{c,d}});        
    }
    sort(vec.begin(), vec.end(), compare);

    // for (int i=0; i<n; i++){
    //     cout<<vec[i].first.first<<" " <<vec[i].first.second<< " "<<vec[i].second.first << " "<<vec[i].second.second<<'\n';
    // }
    pair<int,int> cur = {3,1};
    pair<int,int> endDay = {11,30}; 
    pair<int,int> best = {0,0};  
    int idx = 0, ans = 0;

    while (leq(cur, endDay)) {
        bool found = false;
        while (idx < n && leq(vec[idx].first, cur)) {
            if (great(vec[idx].second, best)) {
                best = vec[idx].second;
                found = true;
            }
            idx++;
        }
        if (!found) { // 연결 불가능
            cout << 0;
            return 0;
        }
        ans++;
        cur = best;
        if (great(cur, endDay)) break;
    }

    cout << ans;

}