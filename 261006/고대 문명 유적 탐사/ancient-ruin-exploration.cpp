#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k, m;
vector<vector<int>> graph;
vector<vector<int>> tmpgraph;
vector<vector<int>> visited;
vector<int> vec;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };


void rotate90(vector<vector<int>>& tmpgraph, int i, int j) {
    vector<vector<int>> tmp = tmpgraph;
    for (int a = i - 1; a <= i + 1; a++) {
        for (int b = j - 1; b <= j + 1; b++) {
            int na = i + (b - j);
            int nb = j - (a - i);
            tmpgraph[na][nb] = tmp[a][b];
        }
    }
}


int bfs(vector<vector<int>>& map, int i, int j, int val) {
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    q.push({ i, j });

    int cnt = 1;

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= 5 || nj < 0 || nj >= 5) continue;

            if (!visited[ni][nj] && map[ni][nj] == val) {
                cnt++;
                visited[ni][nj] = 1;
                q.push({ ni, nj });
            }
        }
    }

    return cnt;
}

int calculate() {
    visited.assign(5, vector<int>(5, 0));

    int result = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!visited[i][j]) {
                int area = bfs(tmpgraph, i, j, tmpgraph[i][j]);

                if (area >= 3) {
                    result += area;
                }
            }
        }
    }

    return result;
}

int idx = 0;

// 열 오름차순, 같은 열이면 행 내림차순 (pair: first=행, second=열)
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

// 수정: 제거 대상 좌표를 out에 모으기만 하고, 채우기는 하지 않음
int simul_bfs(int i, int j, int val, vector<pair<int, int>>& out) {
    queue<pair<int, int>> q;
    visited[i][j] = 1;
    q.push({ i, j });

    int cnt = 1;

    vector<pair<int, int>> tmpvec;
    tmpvec.push_back({ i,j });

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= 5 || nj < 0 || nj >= 5) continue;

            if (!visited[ni][nj] && graph[ni][nj] == val) {
                cnt++;
                visited[ni][nj] = 1;
                q.push({ ni, nj });
                tmpvec.push_back({ ni, nj });
            }
        }
    }

    if (cnt >= 3) {
        // 수정: 정렬/채우기 삭제, 좌표만 전달
        out.insert(out.end(), tmpvec.begin(), tmpvec.end());
    }

    return cnt;
}

int simulate() {
    int answer = 0;

    while (true) {
        visited.assign(5, vector<int>(5, 0));
        vector<pair<int, int>> rem;   // 수정: 이번 라운드에 제거될 모든 칸

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!visited[i][j]) {
                    simul_bfs(i, j, graph[i][j], rem);
                }
            }
        }

        if (rem.empty()) break;

        answer += rem.size();

        // 수정: 스캔이 모두 끝난 뒤, 전체를 한 번에 정렬해서 채움
        sort(rem.begin(), rem.end(), compare);
        for (auto& p : rem) {
            graph[p.first][p.second] = vec[idx++];
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> m;
    graph.assign(5, vector<int>(5, 0));
    vec.assign(m, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> vec[i];
    }

    for (int turn = 0; turn < k; turn++) {
        int mi = 0, mj = 0, md = 0;
        int maxval = -1e9;

        // 수정: 루프 순서를 각도 -> 열(j) -> 행(i)로 변경 (동률 시 먼저 만난 후보 유지)
        for (int k = 0; k < 3; k++) {
            for (int j = 1; j <= 3; j++) {
                for (int i = 1; i <= 3; i++) {
                    tmpgraph = graph;
                    for (int c = 0; c <= k; c++) {
                        rotate90(tmpgraph, i, j);
                    }

                    int tmpcalc = calculate();

                    if (maxval < tmpcalc) {
                        maxval = tmpcalc;
                        mi = i; mj = j; md = k;
                    }
                }
            }
        }

        // 수정: 얻을 수 있는 유물이 없으면 회전도 하지 않고 즉시 종료
        if (maxval == 0) break;

        tmpgraph = graph;
        for (int c = 0; c <= md; c++) {
            rotate90(tmpgraph, mi, mj);
        }
        graph = tmpgraph;

        int answer = simulate();

        cout << answer << ' ';
    }
    return 0;
}