#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; int m;
		int priority;
		cin >> n >> m;
		deque<pair<int,int>> dq;
		int result = 1;
		for (int i = 0; i < n; i++) {
			cin >> priority;
			dq.push_back({ i, priority});
		}
		
		while (true){
			for (int i = 1; i < dq.size(); i++) {
				if (dq.front().second < dq[i].second) {
					dq.push_back(dq.front());
					dq.pop_front();
					i = 0;
				}
			}
			if (dq.front().first == m) {
				cout << result << "\n";
				break;
			}
			else {
				result++;
				dq.pop_front();
			}
		}
	}
}