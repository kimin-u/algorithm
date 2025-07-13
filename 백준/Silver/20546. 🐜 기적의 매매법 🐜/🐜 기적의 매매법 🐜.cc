#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int money_j, money_s;
	cin >> money_j;
	money_s = money_j;

	vector<int> vec;
	for (int i = 0; i < 14; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}

	//준현
	int cnt_j = 0;
	for (int i = 0; i < 14; i++) {
		int num = money_j / vec[i];
		cnt_j += num;
		money_j -= vec[i] * num;
	}
	int total_j = money_j + (cnt_j * vec.back());

	//성민
	int cnt_s = 0;
	int incline = 0;
	int decline = 0;
	for (int i = 1; i < 14; i++) {
		if (vec[i - 1] < vec[i]) {
			incline++;
			decline = 0;
		}
		else if (vec[i - 1] > vec[i]) {
			incline = 0;
			decline++;
		}
		else {
			incline = 0; decline = 0;
		}

		if (incline == 3) {// 전량 매도 
			money_s += vec[i] * cnt_s;
			cnt_s = 0;
			incline = 0;
		}
		if (decline == 3) {
			int num = money_s / vec[i];
			cnt_s += num;
			money_s -= vec[i] * num;
			decline = 0;
		}
	}
	int total_s = money_s + (cnt_s * vec.back());

	if (total_j > total_s)
		cout << "BNP";
	else if (total_j < total_s)
		cout << "TIMING";
	else
		cout << "SAMESAME";
	

}