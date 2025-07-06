#include <iostream>
#include <vector>

using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vec1.assign(21, -1);
	vec2.assign(21, -1);
	dp.assign(21, vector<int>(2,1e9));

	for (int i = 1; i < n; i++)
		cin >> vec1[i] >> vec2[i];

	int k; cin >> k;

	dp[1][0] = 0;
	dp[2][0] = dp[1][0] + vec1[1];
	dp[3][0] = min(dp[2][0] + vec1[2], dp[1][0] + vec2[1]);
	dp[4][0] = min(dp[3][0] + vec1[3], dp[2][0] + vec2[2]);
	dp[4][1] = dp[1][0] + k;

	for (int i = 5; i < n+1; i++) {
		// 작은 점프
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + vec1[i - 1]);
		dp[i][1] = min(dp[i][1], dp[i - 1][1] + vec1[i - 1]);
		// 큰 점프
		dp[i][0] = min(dp[i][0], dp[i - 2][0] + vec2[i - 2]);
		dp[i][1] = min(dp[i][1], dp[i - 2][1] + vec2[i - 2]);
		// 매우 큰 점프는 아직 안 쓴 경우만
		dp[i][1] = min(dp[i][1], dp[i - 3][0] + k);
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';


}