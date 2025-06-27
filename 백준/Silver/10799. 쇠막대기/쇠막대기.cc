#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	stack<string> st;
	int result = 0;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push("(");
		}
		else if (str[i] == ')') {
			st.pop();

			if (str[i-1] =='(') {
				result += st.size();
			}
			else {
				result++;
			}
		}
	}

	cout << result;

}


