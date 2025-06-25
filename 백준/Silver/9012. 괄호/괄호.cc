#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		stack<char> s;
		for (auto c : str) {
			if (c == '(') {
				s.push(c);
			}
			else if (c == ')') {
				if (!s.empty())
					s.pop();
				else {
					s.push(c);
					break;
				}
			}
		}
		if (s.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}