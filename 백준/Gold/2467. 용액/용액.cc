#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector<int> vec;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}

	int left, right;
	left = 0; right = n - 1;
	int min = 2e9;
	while (left < right) {
		int tmp = vec[left] + vec[right];

		if (abs(tmp) <=  min) {
			min = abs(tmp);
			result.clear();
			result.push_back(vec[left]);
			result.push_back(vec[right]);
		}
		if (tmp < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	for (auto r : result) {
		cout << r << " ";
	}

}