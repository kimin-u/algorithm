#include <queue>
#include <iostream>

using namespace std;

int n;
int x;

struct compare{
  bool operator()(int a, int b){
    return a>b;
  }  
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    priority_queue<int, vector<int>, compare> q;

    while (n--){
        cin>>x;
        if (x>0) q.push(x);
        else if (x==0) {
            if (q.empty()){
                cout<<0<<'\n';
            }
            else{
                cout<<q.top()<<'\n';
                q.pop();
            }
        }
    }
}