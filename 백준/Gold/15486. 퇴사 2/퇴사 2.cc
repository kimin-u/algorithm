#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> t;
vector<int> p;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	t.assign(n + 1, -1);
	p.assign(n + 1, -1);
	dp.assign(n + 2, -1);

	for (int i = 1; i < n + 1; i++)
		cin >> t[i] >> p[i];

	dp[1] = 0;
	for (int i = 1; i < n + 1; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		
		if (i + t[i] <= n + 1)
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}

	cout << dp[n + 1];
}