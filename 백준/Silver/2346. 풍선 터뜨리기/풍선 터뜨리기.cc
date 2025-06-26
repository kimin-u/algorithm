#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> dq;
	deque<int> dq_num;
	vector<int> v;
	int n; cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		dq.push_back(i+1);
		dq_num.push_back(num);
	}

	v.push_back(1);
	int tmp;
	tmp = dq_num.front();
	dq.pop_front();
	dq_num.pop_front();

	while (!dq.empty()) {
		if (tmp > 0) {
			for (int i = 0; i < tmp-1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
				dq_num.push_back(dq_num.front());
				dq_num.pop_front();
			}
			v.push_back(dq.front());
			dq.pop_front();
			tmp = dq_num.front();
			dq_num.pop_front();
		}
		else {
			for (int i = 0; i < (-tmp) - 1; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
				dq_num.push_front(dq_num.back());
				dq_num.pop_back();
			}
			v.push_back(dq.back());
			dq.pop_back();
			tmp = dq_num.back();
			dq_num.pop_back();
		}
	}

	for (const auto& i : v) {
		cout << i << " ";
	}
}