#include <iostream>
#include <vector>

using namespace std;

int x, y;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> x >> y;
	dp.assign(x + 1, vector<int>(y + 1, 0));
	//dp[i][j] = i개의 1, j개의 0을 사용했을 때 수열 경우의 수.
	// 000
	// 011
	// 101
	// 110
	dp[0][0] = 1;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			// 000 : 3개 0
			if (j + 3 <= y) {
				dp[i][j + 3] = (dp[i][j + 3] + dp[i][j]) % 1000000007;
			}
			// 011 : 1개 0, 2개 1
			if (i + 2 <= x && j + 1 <= y) {
				dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % 1000000007;
			}
			//101 : 1개 0, 2개 1
			if (i + 2 <= x && j + 1 <= y) {
				dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % 1000000007;
			}
			//110 : 1개 0 2개 1
			if (i + 2 <= x && j + 1 <= y) {
				dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % 1000000007;
			}
		}
	}

	cout << dp[x][y];

}