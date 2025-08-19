#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INTMAX 100001
using namespace std;

int n, k;
queue<pair<int, int>> q;
vector<int> visit;
int timee= INTMAX;
int cnt = 0;

void bfs(void) {
	while (!q.empty()) {
		int tmpi = q.front().first;
		int tmptime = q.front().second;
		q.pop();
		visit[tmpi] = true;
		if (tmpi == k && cnt != 0 && timee == tmptime) cnt++;

		if (cnt == 0 && tmpi == k) {
			timee = tmptime;
			cnt++;
		}

		else {
			if (tmpi * 2 >= 0 && tmpi * 2 < INTMAX && visit[tmpi * 2] == false) {
				q.push({ tmpi * 2, tmptime + 1 });
			}
			if (tmpi + 1 >= 0 && tmpi + 1 < INTMAX && visit[tmpi + 1] == false) {
				q.push({ tmpi + 1, tmptime + 1 });
			}
			if (tmpi - 1 >= 0 && tmpi - 1 < INTMAX && visit[tmpi - 1] == false) {
				q.push({ tmpi - 1, tmptime + 1 });
			}


		}
	}
}

int main(void)
{
	cin >> n >> k;
	q.push({ n,0 });
	visit.assign(INTMAX, 0);
	visit[n] = 1;

	bfs();
	cout << timee << "\n" << cnt;

	return 0;

}