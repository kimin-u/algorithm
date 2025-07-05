#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main(void) {
	cin >> n >> k;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}

	sort(lst.begin(), lst.end());

	vector<int> dist;
	for (int i = 0; i < n - 1; i++) {
		dist.push_back(lst[i + 1] - lst[i]);
	}

	sort(dist.begin(), dist.end());

	/*for (int i = 0; i < n - 1; i++) {
		cout << dist[i] << " ";
	}*/
	// 앞에서부터 n-k개;

	int result = 0;
	for (int i = 0; i < n - k; i++) {
		result += dist[i];
	}

	cout << result;
	return 0;
}
