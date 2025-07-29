#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> vec;

		long long int result = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			vec.push_back(num);
		}

		int max_price = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (max_price < vec[i]) {
				max_price = vec[i];
			}
			else {
				result += (max_price - vec[i]);
			}
		}
		cout << result << "\n";
	}
}