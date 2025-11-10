#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;

vector<pair<int, int>> jewel;
vector<int> bag;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

bool compare2(int a, int b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin>>n>>k;
    jewel.assign(n,{0,0});
    bag.assign(k,0);

    for(int i=0; i<n; i++){
        cin>>jewel[i].first>>jewel[i].second;
    }
    for (int i=0; i<k; i++){
        cin>>bag[i];
    }

    sort(jewel.begin(), jewel.end(), compare);
    sort(bag.begin(), bag.end(), compare2);

    priority_queue<int, vector<int>, less<int>> pq;
    long long answer = 0;

    int idx = 0;
    for (int i=0; i<k; i++){ //가방
        while (idx < n && jewel[idx].first <= bag[i]){
            pq.push(jewel[idx].second);
            idx++;
        }
        if (!pq.empty()){
            answer += pq.top(); pq.pop();
        }
    }

    cout<<answer;
}