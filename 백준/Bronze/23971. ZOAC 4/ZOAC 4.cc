#include <iostream>

using namespace std;
int h, w, n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w >> n >> m;

	//가로 (m+1) 띄워서 배치
	//1, 1 + (m+1), 1+2(m+1), ... , w까지
	// 1+x(m+1) <= w;
	// x <= (w-1) / (m+1);

	int a = (h - 1) / (n + 1);  // 5/ 3
	int b = (w - 1) / (m + 1);
	a++; b++;
	cout << a * b;
}