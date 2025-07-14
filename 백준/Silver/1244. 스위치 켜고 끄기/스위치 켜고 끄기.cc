#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> switches(n);
	for (int i = 0; i < n; i++) {
		cin >> switches[i];
	}
	int m; cin >> m;
	vector<pair<int, int>> students(m);
	for (int i = 0; i < m; i++) {
		cin >> students[i].first >> students[i].second;
		if (students[i].first == 1) {
			int alpha = 1;
			while (students[i].second * alpha <= n) {
				if (switches[students[i].second * alpha - 1] == 1)
					switches[students[i].second * alpha - 1] = 0;
				else
					switches[students[i].second * alpha - 1] = 1;
				alpha++;
			}
		}
		else {
			int beta = 1; 
			vector<int> tmp;
			tmp.push_back(students[i].second - 1);
			while (true) {
				if (students[i].second - 1 - beta < 0 || students[i].second - 1 + beta >= n) break;
				if (switches[students[i].second - 1 - beta] == switches[students[i].second - 1 + beta]) {
					tmp.push_back(students[i].second - 1 - beta);
					tmp.push_back(students[i].second - 1 + beta);
					beta++;
				}
				else break;

			}
			for (int j = 0; j < tmp.size(); j++) {
				if (switches[tmp[j]] == 1) switches[tmp[j]] = 0;
				else switches[tmp[j]] = 1;
			}

		}
	}

	for (int i = 0; i < switches.size(); i++) {
		cout << switches[i] << " ";
		if ((i+1) % 20 == 0) cout << "\n";
	}
}