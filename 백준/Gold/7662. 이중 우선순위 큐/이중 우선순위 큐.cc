#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--) {
		int k; cin >> k;
		
		unordered_map<int, int> umap;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		priority_queue<int, vector<int>, less<int>> max_pq;
		string str; int num;
		for (int i = 0; i < k; i++) {
			cin >> str >> num;
			if (str == "I") {
				max_pq.push(num);
				min_pq.push(num);
				umap[num]++;
			}
			else {// delete
				if (umap.empty())
					continue;
				if (num == 1) { //delete max_pq
					while (!max_pq.empty()) {
						int tmp = max_pq.top();
						max_pq.pop();
						if (umap.find(tmp) != umap.end() && umap[tmp] > 0) {
							umap[tmp]--;
							if (umap[tmp] == 0) umap.erase(tmp);
							break;
						}
					}
				}
				else { //delete min_pq;
					while (!min_pq.empty()){
						int tmp = min_pq.top();
						min_pq.pop();
						if (umap.find(tmp) != umap.end() && umap[tmp] > 0) {
							umap[tmp]--;
							if (umap[tmp] == 0) umap.erase(tmp);
							break;
						}
					}
				}
			}
		}

		//print max & min value
		if (umap.empty())
			cout << "EMPTY\n";
		else {
			int max, min;
			while (!max_pq.empty()) {
				int tmp = max_pq.top();
				if (umap.find(tmp) != umap.end() && umap[tmp] > 0) {
					max = tmp;
					break;
				}
				max_pq.pop();
			}
			while (!min_pq.empty()) {
				int tmp = min_pq.top();
				if (umap.find(tmp) != umap.end() && umap[tmp] > 0) {
					min = tmp;
					break;
				}
				min_pq.pop();
			}
			cout << max << " " << min << "\n";
		}
		

	}//test case end;
}