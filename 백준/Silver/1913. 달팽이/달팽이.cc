#include <iostream>
#include <vector>

using namespace std;

int n, tag;
vector<vector<int>> vec;
vector<int> di = { -1,0,1,0 };
vector<int> dj = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> tag;
	vec.assign(n, vector<int>(n, 0));

	int i = n / 2;
	int j = n / 2;
	int value = 1;
	int cnt = 0;
	int straight = 1;
	int change_d = 0;
	int d = 0;

	int result_i, result_j;

	while (true) {
		if (value == tag) {
			result_i = i;
			result_j = j;
		}
		vec[i][j] = value++;
		i = i + di[d];
		j = j + dj[d];

		cnt++;
		if (cnt == straight) {
			d = (d + 1) % 4;
			cnt = 0;
			change_d++;
		}
		if (change_d == 2) {
			straight++;
			change_d = 0;
		}
		if (value == n * n + 1) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << vec[i][j];
			if (j != n - 1) cout << " ";
		}
		cout << "\n";
	}
	cout << result_i + 1 << " " << result_j + 1;

}