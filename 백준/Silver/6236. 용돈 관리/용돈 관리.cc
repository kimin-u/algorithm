#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vec.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    int k = 0;
    int left = *max_element(vec.begin(), vec.end());
    int right = 1000000000; //1,000,000,000
    
    while (left <= right){
        int mid = (left+right)/2;

        // mid로 m번 출금 이내로 가능한지
        int cnt =0;
        bool flag = false;
        int balance = 0;
        for (int day =0; day<n; day++){
            if (balance < vec[day]){
                cnt++;
                balance = mid -vec[day];
            }            
            else{
                balance -= vec[day];
            }
        }

        if (cnt <= m ){
            flag = true;
        }

        if (flag) {
            right = mid -1;
            k = mid;
        }
        // mid로 하면 m번 출금 횟수를 넘기는지
        else{
            left = mid + 1;  // 더 큰 값 필요
        }
    }

    cout<<k;


}