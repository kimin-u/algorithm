#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	int l1 = a.length();
	int l2 = b.length();
	dp.assign(l1 + 1, vector<int>(l2 + 1, 0));

	int answer = 0;
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (a[i- 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer;
}