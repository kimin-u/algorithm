#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;
	cout << gcd(a, b) << "\n" << lcm(a, b);
}