#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<long long>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp.assign(1000000 + 1, vector<long long>(2, 0));
	//dp[i] = 길이 i인 문자열 중에서 s, c 합 짝수 개수 
	dp[1][0] = 24; 
	dp[1][1] = 2;
	dp[2][0] = 580;//24*24 + 2*2
	dp[2][1] = 2 * 24 + 2 * 24; // 2*24 + 2*24;
	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] * 24 + dp[i - 1][1] * 2) % 1000000007;
		dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1] * 24) % 1000000007;
	}
	cout << dp[n][0];



}