#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; ++i) {
		string str;
		int num;
		int tmp;
		cin >> str;
		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else
				printf("-1\n");
		}
		else if (str == "size") {
			printf("%d\n", s.size());
		}
		else if (str == "empty") {
			if (!s.empty())
				printf("0\n");
			else
				printf("1\n");
		}
		else if (str == "top") {
			if (!s.empty()) {
				printf("%d\n", s.top());
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}