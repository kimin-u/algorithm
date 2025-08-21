#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int result = 1;
		for (int i = 0; i < n; i++) {
			result *= (m - i);
			result /= (i + 1);
		}
		cout << result << "\n";
	}
}