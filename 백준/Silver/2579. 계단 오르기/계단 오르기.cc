#include <iostream>
#include <vector>
 
using namespace std;

vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> vec(n + 1);
	vector<int> dp(300 + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> vec[i];
	}

	dp[0] = 0;
	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];

	for (int i = 3; i < n + 1; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + vec[i - 1]) + vec[i];
	}
	cout << dp[n];
}