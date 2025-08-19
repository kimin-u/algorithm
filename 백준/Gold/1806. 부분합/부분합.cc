#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + vec[i - 1];
	}

	int left = 0, right = 0;
	int answer = 1e9;
	while (right <= n) {
		int cur = sum[right] - sum[left];
		if (cur >= s) {
			answer = min(answer, right - left);
			left++;
		}
		else {
			right++;
		}
	}

	if (answer == 1e9) cout << 0;
	else cout << answer;
}