#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	string str;


	vector<string> vec(n + 1);
	unordered_map<string, int> map;

	for (int i = 0; i < n; i++) {
		cin >> str;
		vec[i + 1] = str;
		map[str] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> str; 
		if (str[0] >= 'A' && str[0] <= 'Z') { //문자열
			cout << map[str] << "\n";
		}

		else { //숫자.
			int idx = stoi(str);
			cout << vec[idx] << "\n";
		}

	}
}