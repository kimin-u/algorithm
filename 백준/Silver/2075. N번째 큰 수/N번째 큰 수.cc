#include <iostream>	
#include <queue>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n * n; i++) {
		int num; cin >> num;
		if (pq.size() >= n)
			if (pq.top() < num)
				pq.pop();
			else {
				continue;
			}
		pq.push(num);

	}



	cout << pq.top();
} 