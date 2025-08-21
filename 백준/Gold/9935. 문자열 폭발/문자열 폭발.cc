#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	string explode; cin >> explode;
	
	stack<char> st;
	
	int len = explode.length();
	for (auto c : str) {
		st.push(c);

		if (st.size() >= len) {
			string tmp = "";
			for (int i = 0; i < len; i++) {
				tmp += st.top(); st.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp != explode) {
				for (auto t : tmp) {
					st.push(t);
				}
			}
		}

	}

	string tmp = "";
	while (!st.empty()) {
		tmp += st.top(); st.pop();
	}
	if (tmp.empty()) {
		cout << "FRULA";
	}
	else {
		reverse(tmp.begin(), tmp.end());
		for (auto t : tmp) {
			cout << t;
		}
	}
}