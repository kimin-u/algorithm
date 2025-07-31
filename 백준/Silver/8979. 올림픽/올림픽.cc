#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> vec;

bool compare(vector<int> a, vector<int> b) {
	if (a[1] == b[1] && a[2] == b[2]) return a[3] >= b[3];
	else if (a[1] == b[1]) return a[2] >= b[2];
	return a[1] >= b[1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vector<int> tmp; 
		for (int j = 0; j < 4; j++) {
			int t; cin >> t;
			tmp.push_back(t);
		}
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++) {
		if (vec[i][0] == k) cout << i + 1 << "\n";
	}


}