#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	while (dq.size() != 1) {
		dq.pop_front();
		int tmp = dq.front();
		dq.push_back(tmp);
		dq.pop_front();
	}

	cout << dq.front();
}