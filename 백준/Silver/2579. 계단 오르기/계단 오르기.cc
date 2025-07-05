#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> lst(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> lst[i];
	}
	//한번에 하나 또는 두개 오른다 
	//세개 연속으로 밟기 안됨

	//dp[i] = i번째 계단 까지의 최댓값을 의미;
	vector<int> dp(301);
	dp[0] = 0;
	dp[1] = lst[1];
	dp[2] = lst[1] + lst[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + lst[i], dp[i - 3] + lst[i - 1] + lst[i]);
	}

	cout << dp[n];

	return 0;

}