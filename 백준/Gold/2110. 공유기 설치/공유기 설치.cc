#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> c;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	// 거리 사이 최댓값. 
	// 사이 거리를 변수로 해서 탐색

	int start = 1;
	int end = vec.back() - vec[0];
	int answer;
	while (start <= end) {
		long long mid = start + end;
		mid /= 2;
		int last = vec[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (last + mid <= vec[i]) {
				last = vec[i];
				cnt++;
			}
		}

		if (cnt >= c) {
			answer = mid;

			start = mid + 1;
		}
		else {
			end = mid - 1;

		}
	}
	cout << answer;
}