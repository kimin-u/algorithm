#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<long long,int>> vec;

bool compare(pair<long long,int> a, pair<long long, int> b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     
    cin>>n;
    for (int i=0; i<n; i++){
        long long num; cin>>num;
        vec.push_back({num, i});
    }
    //n개 모듈 중 i개 골라서 각각의 기준에 맞게 점수 주기
    sort(vec.begin(), vec.end(), compare);

    vector<long long> summ(n+1,0);
    for (int i=1; i<=n; i++){
        summ[i] = summ[i-1] + vec[i-1].first;
    }

    //높은 모듈부터 추가해가면서 total 값이랑 tmp_total비교
    long long total = 3*(vec[0].first);
    long long tmp_total;
    vector<int> answer;
    int cnt =1;
    for(int i=1; i<n; i++){
        tmp_total =vec[0].first;
        tmp_total += vec[i].first;
        tmp_total += summ[i+1];
        // for (int j=0; j<=i; j++){
        //     tmp_total += vec[j].first;
        // }
        if (total < tmp_total){
            total = tmp_total;
            cnt = i+1;
        }
        
    }

    cout<<cnt<<"\n";

    for (int i=0; i<cnt; i++){
        cout<<vec[i].second + 1<<" ";
    }
}   