#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> di = {-1, 1, 0, 0};
vector<int> dj = {0, 0, -1, 1};

int n;
int si, sj;
int ti, tj;

vector<vector<int>> graph;
vector<vector<int>> visited;


struct compare {
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

int find3num(int cost) {
    if (cost % 3 == 0) return cost;
    int tmp = cost/3;
    int ret = tmp * 3 + 3;
    return ret;
}

int bfs() {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> pq;

    pq.push({{si, sj}, 0});
    visited[si][sj] = 0;

    while (!pq.empty()) {
        int ci = pq.top().first.first;
        int cj = pq.top().first.second;
        int cost = pq.top().second;
        pq.pop();
        
        if (ci == ti && cj == tj) {
            return visited[ci][cj];
        }

        if (cost > visited[ci][cj]) continue;

        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (graph[ni][nj] == 0) {
                if (visited[ni][nj] > cost + 1) {
                    visited[ni][nj] = cost + 1;
                    pq.push({{ni, nj}, visited[ni][nj]});
                }
            }

            else if (graph[ni][nj] == 2) {
                int waittime = (2 - (cost % 3) + 3) % 3;
                int nextcost = cost + waittime + 1;
                if (visited[ni][nj] > nextcost) {
                    visited[ni][nj] = nextcost;
                    pq.push({{ni, nj}, visited[ni][nj]});
                }
            }
        }

    }

    return -1;
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        graph.assign(n, vector<int>(n, 0));
        visited.assign(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        cin >> si >> sj;
        cin >> ti >> tj;

        int answer = bfs();

        cout << "#" << test_case << " " << answer << '\n';


    }
}