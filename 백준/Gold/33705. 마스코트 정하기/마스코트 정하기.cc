#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vec.assign(n, 0);
	int one_cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (vec[i] == 1) one_cnt++;
	}

	// 0번, 1번, 2번 만에 가능
	//0번 case.
	if (one_cnt * 2 >= n) {
		cout << 0;
		return 0;
	}
	//1번 행동 case .
	vector<int> one_sum(n+1, 0);
	for (int i = 0; i < n; i++) {
		if (vec[i] == 1) one_sum[i + 1] = one_sum[i] + 1;
		else one_sum[i + 1] = one_sum[i];
	}

	// L~R 제거 --> 남은 사람 : n-(r-l+1) 
	// 1투표한 사람 수 *2 >= n-(r-l+1) 이면 끝.
	/*
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			int tmp_one = one_cnt - (one_sum[r + 1] - one_sum[l]);
			int people = n - (r - l + 1);
			if (people == 0) continue;
			if (tmp_one * 2 >= people) {
				cout << 1;
				return 0;
			}
		}
	}
	*/
	// 2* 1개수 -n >= 2 * 1제거 - 사람제거. (r-l+1)
	// l없이. 2*1개수-ㅜ >= b[r+1] -b[l] (bi = 2*one_sum[i] -i)
	if (vec[0] == 1 || vec[n-1] == 1) {
		cout << 1;
		return 0;
	}
	vector<int> b(n + 1, 0);
	for (int i = 0; i < n; i++) {
		b[i + 1] = b[i] + (vec[i] == 1 ? 1 : -1);
	}
	int K = b[n];
	int max_b_incl0 = b[0]; 
	int max_b_excl0 = -1e9;

	for (int r = 1; r <= n - 1; r++) {
		if (max_b_incl0 >= b[r] - K) {
			cout << 1 << '\n';
			return 0;
		}
		max_b_incl0 = max(max_b_incl0, b[r]);
		max_b_excl0 = max(max_b_excl0, b[r]); // l>=1 갱신
	}

	if (max_b_excl0 >= b[n] - K) { 
		cout << 1 << '\n';
		return 0;
	}

	//2번 행동 case : 나머지 
	cout << 2;
	return 0;
}