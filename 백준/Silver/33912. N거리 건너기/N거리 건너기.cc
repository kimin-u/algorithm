#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec[i] = num;
	}
	vector<int> light(n + 1);
	for (int i = 0; i < n; i++)
		light[vec[i]] = i;

	long long cw = 0;
	long long ccw = 0;
	
	//시계
	//vec index가 current 일때까지 t++
	//while loop
	// tmp 가 작으면 그만큼 증가시키고
	// 더 크면 남은 사이클 만큼 증가 (남은 사이크ㅡㄹ : 
	int pos = 1;
	long long tmp = 0;
	while (pos != m) {
		int cur = pos;
		pos++;
		if (pos > n) pos = 1;

		//while (vec[tmp % n] != cur) tmp++;
		int target = light[cur];
		if (tmp % n <= target) tmp += target - (tmp % n); //
		else tmp += n - tmp % n + target;
		tmp++;
	}
	cw = tmp;

	//반시계 index를 감소하는 
	//vec가 거꾸로 가야함 cur 한칸 아래로
	pos = 1;
	tmp = 0;

	while (pos != m) {
		int cur;
		if (pos == 1) cur = n;
		else cur = pos - 1;
		pos--;
		if (pos == 0) pos = n;
		//while (vec[tmp % n] != cur) tmp++;
		int target = light[cur];
		if (tmp % n <= target) tmp += target - (tmp % n); //
		else tmp += n - tmp % n + target;
		tmp++;
	}
	ccw = tmp;
	
	if (cw < ccw) cout << "CW";
	else if (cw > ccw) cout << "CCW";
	else cout << "EQ";

}