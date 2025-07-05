#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
	cin >> n;
	vector<int> lst(n);

	for (int i = 0; i < n; i++)
		cin >> lst[i];

	vector<int> dp(n);
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (lst[i] > lst[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
	return 0;
}