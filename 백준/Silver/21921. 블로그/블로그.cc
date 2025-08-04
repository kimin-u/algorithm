#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}

	vector<int> result;
	int sum = 0;
	for (int i = 0; i < x; i++) {
		sum += vec[i];
	}
	
	int max = sum;
	int res = 1;
	for (int i = 1; i <= n - x; i++) {
		sum = sum - vec[i-1] + vec[i + x - 1];
		if (max == sum) res++;
		else if (max < sum) {
			max = sum;
			res = 1;
		}
	}

	if (max == 0) {
		cout << "SAD";
		return 0;
	}

	cout << max << "\n";
	cout << res;

}