#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> dq;
	string str;
	int num;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "front") {
			if (!dq.empty()) 
				cout << dq.front() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back") {
			if (!dq.empty()) 
				cout << dq.back() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "empty") {
			if (dq.empty()) 
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "pop_front") {
			if (!dq.empty()) {
				int tmp = dq.front();
				dq.pop_front();
				cout << tmp << "\n";
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (!dq.empty()) {
				int tmp = dq.back();
				dq.pop_back();
				cout << tmp << "\n";
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
	}


}