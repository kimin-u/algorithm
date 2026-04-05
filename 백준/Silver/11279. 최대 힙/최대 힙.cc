#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, less<>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for (int i=0; i<n; i++){
        int num; cin>>num;
        if (num>0){
            pq.push(num);
        }
        else{
            if (!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
    }

    return 0;
}