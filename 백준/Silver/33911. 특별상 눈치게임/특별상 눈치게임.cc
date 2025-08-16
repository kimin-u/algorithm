#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<int, int> umap;
vector<pair<int, int>> vec;

bool compare(pair<int,int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
/*
vector<int> maxvector() {
	vector<int> ret;
	for (auto v : vec) {
		if (v.second == 1) ret.push_back(v.first);
		if (ret.size() == 3) break;
	}
	return ret;
}
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//중복을 먼저 제거하면 안됨
	//vector sorting 하고 경우의 수 구하기? 
	//전역 탐색.
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp; cin >> tmp;
			umap[tmp]++;
		}
	}
	for (auto u : umap) 
		vec.push_back({ u.first, u.second });
	sort(vec.begin(), vec.end(), compare);


	int answer = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			for (int k = j + 1; k <= 100; k++) {
				vector<int> tmp = { k,j,i };
				vector<int> remain;
				vector<int> my_remain;
				for (int t = 1; t <= 100; t++) {
					int cnt = umap[t];
					if (cnt == 1 && find(tmp.begin(), tmp.end(), t) == tmp.end()) remain.push_back(t);
				}

				for (auto t : tmp) {
					if (umap[t] == 0) my_remain.push_back(t);
				}
				remain.insert(remain.end(), my_remain.begin(), my_remain.end());
				if (remain.size() == 0) continue;
				int mx = *max_element(remain.begin(), remain.end());
				if (find(tmp.begin(), tmp.end(), mx) != tmp.end()) answer++;



			}
		}
	}
	cout << answer;
}