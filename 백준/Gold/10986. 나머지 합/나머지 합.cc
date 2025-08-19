#include <iostream>
#include <vector>


using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vec.assign(n, 0); vector<long long> sum(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	//sum[i] = vec[0] + ...  + vec[i-1]; 
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + vec[i - 1];
	}
	//i~j 누적합 : sum[j+1] - sum[i];
	// sum[j+1] % m == sum[i] % m 이 같은 i,j쌍의 개수
	vector<long long> cnt(m, 0);
	long long answer = 0;
	for (int i = 0; i <= n; i++) {
		int r = sum[i] % m;
		answer += cnt[r]++;
	}
	cout << answer;
}


	