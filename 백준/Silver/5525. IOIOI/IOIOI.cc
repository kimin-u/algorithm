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
	/*
	for (int i = 0; i <= m - (2 * n + 1); i++) {
		//string tt = str.substr(i, 2 * n + 1);
		//if (tt == tmp) answer++;
		bool match = true;
		for (int j = 0; j < 2 * n + 1; j++) {
			if (tmp[j] != str[i + j]) {
				match = false;
				break;
			}
		}
		if (match) answer++;
	}
	*/
	int i = 0;
	while (i < m - 1) {
		int cnt = 0;
		while (i + 2 < m && str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
			cnt++;
			i += 2; // 한 쌍(OI)씩 이동
		}
		if (cnt >= n) answer += (cnt - n + 1); // 겹치는 PN도 포함
		i++;
	}

	cout << answer;
}