#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> di = { 1,1,0,-1 }; //아래, 우하향, 우측, 우상향
vector<int> dj = { 0,1,1,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n = 19;
	map.assign(n, vector<int>(n));

	//handle input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//implementation
	int result_i, result_j;
	int ci, cj;
	int cnt;
	int direction = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cnt = 0;
			direction = 0;
			if (map[i][j] == 0) continue;

			else if (map[i][j] == 1) {
				for (direction=0; direction<4; direction++) {
					ci = i; cj = j;
					cnt = 1;
					while (true) {
						ci += di[direction];
						cj += dj[direction];

						if (ci < 0 || ci >= 19 || cj < 0 || cj >= 19) break;

						if (map[ci][cj] == 1) cnt++;
						else break;
					}
					if (cnt == 5) {
						int pi = i - di[direction];
						int pj = j - dj[direction];
						if (!(pi < 0 || pi >= 19 || pj < 0 || pj >= 19) && map[pi][pj] == 1) continue;
						cout << "1\n";
						cout << i + 1 << " " << j + 1;
						return 0;
					}
				}
			}

			else { //map[i][j] == 2 case.
				for (direction =0; direction <4; direction ++){
					ci = i; cj = j;
					cnt = 1;
					while (true) {
						ci += di[direction];
						cj += dj[direction];

						if (ci < 0 || ci >= 19 || cj < 0 || cj >= 19) break;

						if (map[ci][cj] == 2) cnt++;
						else break;
					}
					if (cnt == 5) {
						int pi = i - di[direction];
						int pj = j - dj[direction];
						if (!(pi < 0 || pi >= 19 || pj < 0 || pj >= 19) && map[pi][pj] == 2) continue;
						cout << "2\n";
						cout << i + 1 << " " << j + 1;
						return 0;
					}
				}
			}
		}
	}

	cout << "0";
	return 0;

}