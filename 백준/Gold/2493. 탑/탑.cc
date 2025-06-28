#include <iostream>
#include <stack>
using namespace std;

int n;


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	cin >> n;

    stack<pair<int, int> > tower;  //index, height ;
    int height;


    for (int i = 0; i < n; i++) {
        cin >> height;

        while (!tower.empty()) {
            if (height < tower.top().second) {
                cout << tower.top().first << " ";
                break;
            }
            //수신탑 찾을 때까지 계속 pop
            tower.pop();
        }
        //수신 탑이 없다면
        if (tower.empty()) {
            cout << 0 << " ";
        }
        //현재 높이를 스택에 푸쉬
        tower.push(make_pair(i + 1, height));
    }

    return 0;
}