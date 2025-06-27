#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> vec;
	vector<string> result;
	stack<int> st;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	
	int tmp = 1;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int target = vec[i];
		while (tmp <= target) {
			st.push(tmp);
			tmp++;
			result.push_back("+");
		}

		if (st.top() == target) {
			st.pop();
			result.push_back("-");
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}

	for (auto v : result) {
		cout << v << "\n";
	}

}