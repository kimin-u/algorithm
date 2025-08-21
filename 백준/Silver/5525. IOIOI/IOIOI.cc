#include <iostream>
#include <string>

using namespace std;

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	string str; cin >> str;
	//
	string tmp = "";
	for (int i = 0; i < 2 * n + 1; i++) {
		if (i % 2 == 0) tmp += 'I';
		else tmp += 'O';
	}
	int answer = 0;
	
	for (int i = 0; i <= m - (2 * n + 1); i++) {
		string tt = str.substr(i, 2 * n + 1);
		if (tt == tmp) answer++;
	}

	cout << answer;
}