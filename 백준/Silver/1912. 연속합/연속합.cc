#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vec.assign(n + 1, -1);
	dp.assign(n + 1, -10001);

	for (int i = 1; i < n + 1; i++)
		cin >> vec[i];

	dp[1] = vec[1];

	for (int i = 2; i < n + 1; i++) {
		dp[i] = max(vec[i], dp[i - 1] + vec[i]);
	}

	cout << *max_element(dp.begin(), dp.end());
}