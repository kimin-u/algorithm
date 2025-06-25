#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	vector<int> result;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	while (!dq.empty()) {
		for (int i = 0; i < k-1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		result.push_back(dq.front());
		dq.pop_front();
	}

	cout << "<";
	for (int i = 0; i < result.size(); i++) {
		if (i!=result.size()-1)
			cout << result[i] << ", ";
		else {
			cout << result[i];
		}
	}
	cout << ">";

	return 0;
}