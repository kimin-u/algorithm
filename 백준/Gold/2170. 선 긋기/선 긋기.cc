#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;


int n;
vector<pair<int,int>> vec;

bool compare(pair<int, int>a, pair<int, int> b){
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

    ll answer = 0; 
    int start = vec[0].first;
    int end = vec[0].second;
    for (int i=1; i<n; i++){
        int tmpstart = vec[i].first;
        int tmpend = vec[i].second;
        if (tmpstart >= start && tmpstart <= end){
            end = max(end,tmpend);
        }
        else{
            answer += (end-start);
            start = tmpstart;
            end = tmpend;
        }
    }

    answer += (end-start);

    cout<<answer;
}