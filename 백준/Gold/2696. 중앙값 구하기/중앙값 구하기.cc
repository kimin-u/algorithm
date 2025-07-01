#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int m; cin >> m;

        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        vector<int> result;

        for (int i = 0; i < m; ++i) {
            int num; cin >> num;

            if (max_pq.size() == min_pq.size()) max_pq.push(num);
            else min_pq.push(num);

            if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
                int a = max_pq.top(); max_pq.pop();
                int b = min_pq.top(); min_pq.pop();
                max_pq.push(b); min_pq.push(a);
            }

            if ((i + 1) % 2 == 1) { // 홀수 번째 입력마다 중앙값 저장
                result.push_back(max_pq.top());
            }
        }

        cout << result.size() << "\n";

        for (int i = 0; i < result.size(); ++i) {
    if (i > 0 && i % 10 == 0) cout << "\n";
    
    cout << result[i];
    if ((i + 1) % 10 != 0 && i != result.size() - 1) cout << " ";
}
cout << "\n";

    }

    return 0;
}
