#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

struct State {
    int ri, rj, bi, bj, moves;
};

int n, m;
vector<vector<char>> graph;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

// 이동 함수: 이제 상대 구슬 위치를 고려하지 않고 벽/구멍만 체크합니다.
pair<int, int> move_bead(int &i, int &j, int d, int &dist) {
    dist = 0;
    while (graph[i + di[d]][j + dj[d]] != '#' && graph[i][j] != 'O') {
        i += di[d];
        j += dj[d];
        dist++;
        if (graph[i][j] == 'O') break;
    }
    return {i, j};
}

int bfs(int ri, int rj, int bi, int bj) {
    queue<State> q;
    q.push({ri, rj, bi, bj, 1});
    
    // 방문 배열: [red_i][red_j][blue_i][blue_j]
    static bool visited[11][11][11][11] = {false};
    visited[ri][rj][bi][bj] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.moves > 10) break; // 10번 넘어가면 종료

        for (int d = 0; d < 4; d++) {
            int nri = cur.ri, nrj = cur.rj, nbi = cur.bi, nbj = cur.bj;
            int r_dist = 0, b_dist = 0;

            // 각각 독립적으로 끝까지 이동
            move_bead(nri, nrj, d, r_dist);
            move_bead(nbi, nbj, d, b_dist);

            // 파란 구슬이 구멍에 빠지면 무조건 실패 (빨간 구슬과 동시에 빠져도 실패)
            if (graph[nbi][nbj] == 'O') continue;
            
            // 빨간 구슬만 구멍에 빠지면 성공!
            if (graph[nri][nrj] == 'O') return cur.moves;

            // 둘 다 구멍이 아닌데 위치가 같다면, 더 많이 움직인 놈을 한 칸 뒤로
            if (nri == nbi && nrj == nbj) {
                if (r_dist > b_dist) {
                    nri -= di[d]; nrj -= dj[d];
                } else {
                    nbi -= di[d]; nbj -= dj[d];
                }
            }

            if (!visited[nri][nrj][nbi][nbj]) {
                visited[nri][nrj][nbi][nbj] = true;
                q.push({nri, nrj, nbi, nbj, cur.moves + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int start_ri, start_rj, start_bi, start_bj;
    cin >> n >> m;
    graph.assign(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') {
                start_ri = i; start_rj = j;
                graph[i][j] = '.';
            } else if (graph[i][j] == 'B') {
                start_bi = i; start_bj = j;
                graph[i][j] = '.';
            }
        }
    }

    cout << bfs(start_ri, start_rj, start_bi, start_bj) << endl;
    return 0;
}