#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for (int i=0; i<s.size(); i++){
        if (s[i] == '('){
            st.push('(');
        }
        else{
            if (!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    
    if (!st.empty()) return false;
    return true;
}