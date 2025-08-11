#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> vec(4);
	for (int i = 0; i < 4; i++) {
		cin >> vec[i];
	}
	//s:3 c:6개 필요
	int s = vec[0] + vec[3];
	int c = vec[1] + 2*vec[2];

	int answer = 0;
	while (true) {
		if (s >= 3 && c >= 6) {
			s -= 3;
			c -= 6;
			answer++;
		}
		else break;
	}
	cout << answer;

}