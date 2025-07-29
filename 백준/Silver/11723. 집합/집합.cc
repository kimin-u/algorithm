#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m; cin >> m;

	set<int> s;
	set<int> tmp_s;
	for (int i = 1; i <= 20; i++) {
		tmp_s.insert(i);
	}
	while (m--) {
		string str; cin >> str;
		int x;
		if (str == "add") {
			cin >> x;
			s.insert(x);
		}
		else if (str == "remove") {
			cin >> x;
			s.erase(x);
		}
		else if (str == "check") {
			cin >> x;
			if (s.find(x) == s.end()) cout << "0\n";
			else cout << "1\n";
		}
		else if (str == "toggle") {
			cin >> x;
			if (s.find(x) == s.end()) s.insert(x);
			else s.erase(x);
		}
		else if (str == "all") {
			s = tmp_s;
		}
		else if (str == "empty") {
			s.clear();
		}
	}
}
