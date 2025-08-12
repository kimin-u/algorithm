#include <iostream>

using namespace std;

int n;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	long long answer = 0;
	
	int left = n - 1;
	while (left != 0) {
		answer += left--;
		answer++;
	}
	answer++;
	cout << answer;

}