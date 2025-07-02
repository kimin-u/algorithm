#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;

	int cnt = 0;
	while (true) {
		if (a == b) {
			cout << cnt+1;
			break;
		}
		if (b < a) {
			cout << "-1";
			return 0;
		}

		if (b % 10 == 1) {
			b -= 1;
			b /= 10;
			cnt++;
			continue;
		}

		else if (b % 2 == 0) {
			b /= 2;
			cnt++;
			continue;
		}

		else {
			cout << "-1";
			return 0;
		}
	}

}