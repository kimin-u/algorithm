#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int n = numbers.size();
    answer.assign(n,-1);
    
    stack<int> st;
    
    for (int i=n-1; i>=0; i--){
        if (st.empty()){
            answer[i] = -1;
            st.push(numbers[i]);
        }
        else {
            //stack에 수가 남아 있는 경우.
            while (!st.empty()){
                if (numbers[i] < st.top()){
                    answer[i] = st.top();
                    break;
                }
                else {
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        answer[i] = -1;
                    }
                }
            }
            st.push(numbers[i]);
        }
    }
    
    /*
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (numbers[j] > numbers[i]){
                answer[i] = numbers[j];
                break;
            }
        }    
    }
    */
    
    return answer;
}