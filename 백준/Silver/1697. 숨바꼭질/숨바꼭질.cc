#include <iostream>
#include <queue>
#include <vector>

#define INTMAX 100001
using namespace std;

int n, k;
queue<pair<int, int>> q;
vector<bool> visit;
int timee;

int bfs(void) {
	while (!q.empty()) {
		int tmpi = q.front().first;
		int tmptime = q.front().second;
		q.pop();

		if (tmpi == k) return tmptime;

		else {
			if (tmpi*2>=0 && tmpi*2 <INTMAX && visit[tmpi * 2] == false) {
				q.push({ tmpi * 2, tmptime + 1 });
				visit[tmpi * 2] = true;
			}
			if (tmpi + 1 >= 0 && tmpi + 1 < INTMAX && visit[tmpi + 1] == false) {
				q.push({ tmpi + 1, tmptime + 1 });
				visit[tmpi + 1] = true;
			}
			if (tmpi -1 >= 0 && tmpi -1 < INTMAX && visit[tmpi - 1] == false) {
				q.push({ tmpi - 1, tmptime + 1 });
				visit[tmpi - 1] = true;
			}
			
			
		}
	}
}

int main(void)
{
	cin >> n >> k;
	q.push({ n,0 });
	visit.assign(INTMAX, false);
	visit[n] = true;

	timee = bfs();

	cout << timee;

	return 0;

}