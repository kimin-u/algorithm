#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isFullQuack(const string& s) {
	int len = s.size();
	if (len % 5 != 0) return false;
	for (int i = 0; i < len; i += 5) {
		if (s.compare(i, 5, "quack") != 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	int cnt = 0;
	vector<string> vec;

	//q, u, a, c, k
	for (int i = 0; i < str.size(); i++) {
		int vec_size; 
		if (str[i] == 'q') {
			int flag = 0;
			vec_size = vec.size();
			for (int j = 0; j < vec_size; j++) {
				if (!vec[j].empty() && vec[j].back() == 'k') {
					vec[j] = "q";  // 초기화 후 'q'부터 다시 시작
                    flag = 1;
                    break;
				}
			}
			if (!flag)
				vec.push_back("q");
		}
		else if (str[i] == 'u') {
			vec_size = vec.size(); 
			int flag = 0;
			for (int j = 0; j < vec_size; j++) {
				if (!vec[j].empty() && vec[j].back() == 'q') {
					vec[j].push_back('u');
					flag = 1;
					break;
				}
			}
			if (!flag) { cout << "-1"; return 0; }
		}
		else if (str[i] == 'a') {
			vec_size = vec.size();
			int flag = 0;
			for (int j = 0; j < vec_size; j++) {
				if (!vec[j].empty() && vec[j].back() == 'u') {
					vec[j].push_back('a');
					flag = 1;
					break;
				}
			}
			if (!flag) { cout << "-1"; return 0; }

		}		
		else if (str[i] == 'c') {
			vec_size = vec.size();
			int flag = 0;
			for (int j = 0; j < vec_size; j++) {
				if (!vec[j].empty() && vec[j].back() == 'a') {
					vec[j].push_back('c');
					flag = 1;
					break;
				}
			}
			if (!flag) { cout << "-1"; return 0; }

		}
		else if (str[i] == 'k') {
			vec_size = vec.size();
			int flag = 0;
			for (int j = 0; j < vec_size; j++) {
				if (!vec[j].empty() && vec[j].back() == 'c') {
					vec[j].push_back('k');
					flag = 1;
					break;
				}
			}
			if (!flag) { cout << "-1"; return 0; }

		}
	}

	for (int i = 0; i < (int)vec.size(); i++) {
		if (!vec[i].empty()) {
			if (!isFullQuack(vec[i])) {
				cout << -1;
				return 0;
			}
			cnt++;
		}
	}

	cout << cnt;
}