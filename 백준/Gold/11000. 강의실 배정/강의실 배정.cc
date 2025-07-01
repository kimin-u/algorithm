#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n; cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		vec.push_back({ s,t });
	}
	sort(vec.begin(), vec.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto v : vec) {
		if (!pq.empty()) {
			if (pq.top() <= v.first) {
				pq.pop();
			}
		}
		pq.push(v.second);
	}

	cout << pq.size();

}