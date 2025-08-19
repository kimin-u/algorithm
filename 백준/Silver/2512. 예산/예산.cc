#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cin >> m;
	int low = 0;
	int high = *max_element(vec.begin(), vec.end());

	int sum = 0;
	int answer = 0;
	while (low <= high) {
		sum = 0;
		int mid = low + high;
		mid /= 2;

		for (auto v : vec) {
			if (v > mid)  sum += mid;
			else sum += v;
		}
		if (sum > m) {
			high = mid -1;
		}
		else {
			answer = mid;
			low = mid + 1;
		}
	}

	cout << answer;
}