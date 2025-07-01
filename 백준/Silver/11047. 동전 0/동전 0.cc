#include <iostream>
#include <vector>

using namespace std;
vector<int> coin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		coin.push_back(num);
	}
	int result = 0;

	for (int i = n - 1; i >= 0; i--) {
		while (k >= coin[i]) {
			k -= coin[i];
			result++;
		}
	}

	cout << result;
}