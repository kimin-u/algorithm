#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	unordered_map<int, int> umap;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		umap[num]++;
	}

	cin >> m;
	vector<int> answer;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		answer.push_back(umap[num]);
	}

	for (auto a : answer) {
		cout << a << " ";
	}
}