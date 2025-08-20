#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> hp;
vector<int> happy;
vector<int> dp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		hp.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		happy.push_back(num);
	}

	dp.assign(101, 0);
	//dp[i] 체력 i만큼 썻을때 얻을 수 있는 최대 행복.
	for (int i = 0; i < n; i++) {
		int p = hp[i];
		int h = happy[i];

		for (int j = 99; j >= p; j--) {
			dp[j] = max(dp[j], dp[j - p] + h);
		}
	}
	int answer = *max_element(dp.begin(), dp.end());

	cout << answer;
}