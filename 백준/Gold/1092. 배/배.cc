#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool compare(int a, int b) {
	if (a > b) return true;
	return false;
}

int main(void) {
	cin >> n;
	vector<int> crain(n);
	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}
	
	cin >> m;
	vector<int> box(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	int time = 0;
	
	sort(crain.begin(), crain.end(), compare);
	sort(box.begin(), box.end(), compare);

	if (box[0] > crain[0]) {
		cout << -1; 
		return 0;
	}

	while (true) {
		int index = 0;
		for (int i = 0; i < m; i++) {
			if (index == n) break;
			if (crain[index] >= box[i]) {
				index++;
				box.erase(box.begin() + i);
				m--;
				i--;
			}

		}
		time++;

		if (box.size() == 0) break;
	}

	cout << time;
	return 0;
}