#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec;
bool compare(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++){
        int num; cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), compare);
    //15 10
    //로프를 추가하면서 대소비교를 함
    //추가 안하면 일단 처음엔 첫 로프
    // 추가하면 로프수 x 마지막 로프

    int answer = vec[0];
    int cnt = 1;

    for (int i=1; i<vec.size(); i++){
        int tmp = vec[i];
        cnt++;
        int ttmp = tmp * cnt;
        if (answer < ttmp) answer =ttmp;
    }
    cout<<answer;
}