#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
	if (n == 1 || n == 3) return 1;
	if (dp[n] != -1) return dp[n];

	else {
		if (solve(n - 2) == 1) dp[n] = 1;
		else if (solve(n - 4) ==1) dp[n] = 1;
		else if (solve(n - 6) ==1) dp[n] = 1;
		else dp[n] = 0;
		return dp[n];
	}
}
int main(void)
{
	int n; cin >> n;
	dp.assign(n + 1, -1);
	if (solve(n) == true) cout << "SK" << endl;
	else cout << "CY" << endl;
}