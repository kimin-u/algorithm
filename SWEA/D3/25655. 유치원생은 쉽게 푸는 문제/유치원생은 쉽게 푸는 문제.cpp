
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int x;
        cin >> x;
        vector<int> vec = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

        if (x == 1) {
            cout << "0\n";
            continue;
        }

        if (x % 2 == 0) {
            string answer = "";
            for (int i = 0; i < x / 2; i++) {
                answer += '8';
            }
            cout << answer << '\n';
        } else {
            string answer = "4";
            for (int i = 0; i < x / 2; i++) {
                answer += '8';
            }
            cout << answer <<'\n';
        }




    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}