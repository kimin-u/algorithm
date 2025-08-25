#include <queue>
#include <iostream>

using namespace std;

int n,a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    priority_queue<int, vector<int>, less<>> pq;

    while(n--){
        cin>>a;
        
        if (a > 0) {
            for (int i = 0; i < a; i++) {
                int gift;
                cin >> gift;
                pq.push(gift);
            }
        } else {
            if (pq.empty()) cout << "-1\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}