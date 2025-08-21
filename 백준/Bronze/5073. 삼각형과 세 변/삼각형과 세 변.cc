#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec(3);

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (true) {
		vec.assign(3, 0);
		for (int i = 0; i < 3; i++) {
			cin >> vec[i];
		}
		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0) break;

		sort(vec.begin(), vec.end(), compare);

		if (vec[0] >= vec[1] + vec[2]) {
			cout << "Invalid\n";
			continue;
		}
		if (vec[0] == vec[1] && vec[1] == vec[2]) {
			cout << "Equilateral\n";
			continue;
		}
		else if (vec[0] != vec[1] && vec[1] != vec[2] && vec[2] != vec[0]) {
			cout << "Scalene\n";
			continue;
		}
		else {
			cout << "Isosceles\n";
			continue;
		}

	}
}