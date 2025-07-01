#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	priority_queue<int, vector<int>, less<int>> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int max_size = max_pq.size();
		int min_size = min_pq.size();

		if (max_size == min_size) max_pq.push(num);
		else min_pq.push(num);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > min_pq.top()) {
				int a = max_pq.top(); max_pq.pop();
				int b = min_pq.top(); min_pq.pop();

				max_pq.push(b); min_pq.push(a);
			}
		}
		cout << max_pq.top() << "\n";

	}
}