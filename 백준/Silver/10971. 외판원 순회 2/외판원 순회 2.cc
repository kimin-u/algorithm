#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> W;
vector<vector<int>> dp;   // dp[cur][mask]
const int INF = 1e9;

int tsp(int cur, int mask) {
    if (mask == (1 << n) - 1) {        // 모두 방문
        if (W[cur][0] == 0) return INF; // 출발지로 못 돌아가면 불가
        return W[cur][0];
    }
    int &ret = dp[cur][mask];
    if (ret != -1) return ret;
    ret = INF;

    for (int next = 0; next < n; ++next) {
        if (mask & (1 << next)) continue;   // 이미 방문
        if (W[cur][next] == 0) continue;    // 길 없음
        ret = min(ret, W[cur][next] + tsp(next, mask | (1 << next)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    W.assign(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> W[i][j];

    dp.assign(n, vector<int>((1 << n), -1));

    // 0번 도시에서 시작 (어느 도시에서 시작해도 최소 비용은 동일)
    int ans = tsp(0, 1 << 0);
    cout << ans << '\n';
    return 0;
}