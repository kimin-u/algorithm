#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	vector<int> sensor;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		sensor.push_back(num);		
	}
	sort(sensor.begin(), sensor.end());

	vector<int> distance;
	for (int i = 0; i < n-1; i++) {
		int dist = sensor[i + 1] - sensor[i];
		distance.push_back(dist);
	}

	sort(distance.begin(), distance.end(), compare);

	int result = 0;
	for (int i = k - 1; i < distance.size(); i++) {
		result += distance[i];
	}
	cout << result;


}