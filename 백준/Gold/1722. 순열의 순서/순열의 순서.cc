#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;
int num;
ll k;
vector<ll> factorial;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    cin>>num;
    
    factorial.assign(n+1, 1);
    for (int i=1; i<=n; i++){
        factorial[i] = factorial[i-1] * i;
    }

    //1) k입력받고 k번째 수열 출력
    if (num==1){
        cin>>k; k--;
        vector<int> remain;
        for (int i=1; i<=n; i++){
            remain.push_back(i);
        }
        vector<int> answer;
        // 1234, 1243, 1324, 1342, 1423, 1432 //6개.
        //n번째 자리마다 (n-1)! 보다 작은지 큰지. 확인 크면 다음수로 넘어감,.
        // 12 -> 2!보다 큼. 3
        for (int i=n; i>=1; i--){
            ll bsize = factorial[i-1];
            int idx = k/bsize;
            k %= bsize;

            answer.push_back(remain[idx]);
            remain.erase(remain.begin() + idx);
        }
        for (auto x : answer) cout << x << ' ';
    }
    //2) 순열 입력받고 몇번째 수열인지 출력

    else{
        vector<int> perm(n);
        for (int i=0; i<n; i++) cin >> perm[i];

        vector<int> remain;
        for (int i=1; i<=n; i++) remain.push_back(i);

        long long order = 1; // 1-based
        for (int i=0; i<n; i++){
            // 현재 숫자가 남은 수 중 몇 번째인지
            int idx = find(remain.begin(), remain.end(), perm[i]) - remain.begin();
            order += idx * factorial[n - i - 1];
            remain.erase(remain.begin() + idx);
        }

        cout << order;
    }

}