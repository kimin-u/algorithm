#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	//Ai를 Ai+1의 값으로 변경 (횟수제한X)
	// A가 증가하는 수열이면 x 
	// A가 감소할때 바꿔.
	for (int i = vec.size() - 1; i >= 1; i--) {
		if (vec[i] < vec[i - 1])
			vec[i - 1] = vec[i];
	}
	long long  answer = 0;
	for (auto v : vec) {
		answer += v;
	}
	cout << answer;
}