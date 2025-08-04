#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, t, p;
	cin >> n >> t >> p;
	vector<int> score;

	int result = 1;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (t < num) result++;
		score.push_back(num);
	}
	if (n == p && t <= score.back()) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
	}
}