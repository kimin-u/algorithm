#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		string str;
		int num;
		int tmp;
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
		}
		else if (str == "size") {
			printf("%d\n", q.size());
		}
		else if (str == "empty") {
			if (!q.empty())
				printf("0\n");
			else
				printf("1\n");
		}
		else if (str == "front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
			}
			else
				printf("-1\n");
		}
		else if (str == "back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
			}
			else
				printf("-1\n");
		}
	}
}