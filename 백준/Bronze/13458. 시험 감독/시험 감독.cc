#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;
int b,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++){
        int num; cin>>num;
        vec.push_back(num);
    }

    cin>>b>>c;

    long long answer = 0;

    for (int i=0; i<n; i++){
        answer++;
        int tmp = vec[i] - b;
        if (tmp > 0) {
            answer += (tmp + c - 1) / c;
        }
    }
    cout<<answer;
}