#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vector<int> vec;
    for (int i=0; i<n; i++){
        int num; cin>>num;
        vec.push_back(num);
    }

    stack<int> st;
    vector<int> answer(n, -1);

    for (int i=0; i<n; i++) {
        // 스택에 있는 값보다 현재 값이 크면 -> 오큰수
        while (!st.empty() && vec[st.top()] < vec[i]) {
            answer[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i=0; i<n; i++) {
        cout << answer[i] << ' ';
    }   
}