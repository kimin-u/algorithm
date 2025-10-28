#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> vec;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vec.assign(n, vector<int>(3));
    
    for (int i=0; i<n; i++){
        int a, b, c; cin>>a>>b>>c;
        vec[i][0] = a;
        vec[i][1] = b;
        vec[i][2] = c;
    }

    sort(vec.begin(), vec.end(), compare);
    
    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(vec[0][2]);

    for (int i=1; i<n; i++){
        if (pq.top() <= vec[i][1]){
            pq.pop();
        }
        pq.push(vec[i][2]);
    }

    cout<<pq.size();

}