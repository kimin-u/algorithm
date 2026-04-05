#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> answer;
vector<vector<int>> pri_vec;
vector<int> indegree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    pri_vec.assign(n+1, vector<int>());
    indegree.assign(n+1, 0);
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        pri_vec[a].push_back(b);
        indegree[b]++;
    }


    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=1; i<=n; i++){
        if (indegree[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int num = pq.top(); pq.pop();

        answer.push_back(num);

        for (int i=0; i<pri_vec[num].size(); i++){
            int nxt = pri_vec[num][i];
            indegree[nxt]--;
            if (indegree[nxt] == 0){
                pq.push(nxt);
            }
        }
    }

    for (auto a: answer){
        cout<<a<<" ";
    }
}