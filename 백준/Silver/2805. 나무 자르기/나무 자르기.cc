#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<long long> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int low = 0;
	int end = *max_element(vec.begin(), vec.end());
	long long mid;
	int result;
	while (low <= end) {
		mid = end + low;
		mid /= 2;
		long long sum = 0;
		for (auto v : vec) {
			if (v>mid)
				sum += (v-mid);
		}

		if (sum < m) {
			end = mid - 1;
		}
		else {
			result = mid;
			low = mid + 1;
		}
	}
	cout << result;

}