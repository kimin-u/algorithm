#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int p; cin >> p;

	while (p--) {
		int t; cin >> t;
		vector<int> vec; 
		int result = 0;
		for (int i = 0; i < 20; i++) {
			int n; cin >> n;
			int pos = 0;
			while (pos < vec.size() && vec[pos] < n) {
				pos++;
			}
			result += vec.size() - pos;
			vec.insert(vec.begin() + pos, n);

		}
		cout << t<<" "<< result << "\n";
	}
}