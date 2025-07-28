#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> item;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	dp.assign(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int w, v; cin >> w >> v;
		item.push_back({ w,v });
	}

	for (int i = 0; i < n; i++) {
		int w = item[i].first;
		int v = item[i].second;

		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << dp[k] << "\n";
}