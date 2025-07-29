#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> dp(10001, 0);
	dp[0] = 1;
	for (int num : {1, 2, 3}) {
		for (int i = num; i <= 10000; i++) {
			dp[i] += dp[i - num];
		}
	}
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
}