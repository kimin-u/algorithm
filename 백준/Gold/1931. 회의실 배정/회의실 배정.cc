#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		vec.push_back({ start, end });
	}
	sort(vec.begin(), vec.end(), compare);

	int result = 1;
	int tmp_end = vec[0].second;
	for (int i = 1; i < vec.size(); i++) {
		if (tmp_end <= vec[i].first) {
			tmp_end = vec[i].second;
			result++;
		}
	}
	cout << result;

}