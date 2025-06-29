#include <iostream>
#include <string>
#include <stack>


using namespace std;

int isOperation(char c) {
	if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int priority(char c) {
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str; cin >> str;
	string result;
	stack<char> st;
	char tmp;

	bool flag = false;
	for (int i = 0; i < str.size(); i++) {
		if (isOperation(str[i])) { //연산자 case.
			if (str[i] == '(') {
				st.push(str[i]);
				continue;
			}
			else if (str[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					result.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			else { //나머지 연산자.
				while (!st.empty() && priority(st.top()) >= priority(str[i])) {
					result.push_back(st.top()); st.pop();
				}
				st.push(str[i]);
			}
		}

		else { //피연산자.
			result.push_back(str[i]);
		}
	}

	while (!st.empty()) {
		tmp = st.top(); st.pop();
		result.push_back(tmp);
	}

	cout << result;
}