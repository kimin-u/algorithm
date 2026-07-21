#include <string>
#include <vector>
#include <stack>

using namespace std;

int n;

int solution(vector<int> order) {
    int answer = 0;
    n = order.size();
    stack<int> st;
    
    int idx = 0;
    for (int i=1; i<=n; i++){
        int tmp = order[idx];
        if (i == tmp){
            answer++;
            idx++;
        }
        else{
            st.push(i);
        }
        
        while (!st.empty()){
            if (st.top() == order[idx]){
                st.pop();
                idx++;
                answer++;
            }
            else{
                break;
            }
        }
    }
    
    return answer;
}