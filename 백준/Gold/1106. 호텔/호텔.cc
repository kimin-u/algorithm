#include <iostream>
#include <vector>

using namespace std;

vector<int> price;
vector<int> client;
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int c, n; cin >> c >> n;
	price.assign(n + 1, -1);
	client.assign(n + 1, -1);
	dp.assign(100001, -1);

	dp[0] = 0;

	for (int i = 1; i < n + 1; i++)
		cin >> price[i] >> client[i];

	for (int i = 1; i < n + 1; i++) {
		for (int j = price[i]; j < 100001; j++) {
			dp[j] = max(dp[j], dp[j - price[i]] + client[i]);
		}
	}

	for (int i = 0; i < 100001; i++) {
		if (dp[i] >= c) {
			cout << i;
			return 0;
		}
	}


}