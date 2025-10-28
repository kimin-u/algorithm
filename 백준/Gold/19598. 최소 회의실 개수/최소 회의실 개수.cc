#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> vec;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++){
        int start,end; cin>>start>>end;
        vec.push_back({start, end});
    }

    sort(vec.begin(), vec.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto v: vec){
        if (pq.empty()) {
            pq.push(v.second);
            continue;
        }
        if (pq.top() <= v.first){
            pq.pop();
        }
        pq.push(v.second);
    }
    cout<<pq.size();

}