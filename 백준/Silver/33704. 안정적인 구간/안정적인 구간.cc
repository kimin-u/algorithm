#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	//k = B.size(); = j-i+1 
	//중간 원소가 정렬했을 때도 같냐. 
	//k=2) 첫번째 원소 <= 두번째 원소
	//k=3) 두번재 원소가 중간값이냐 .
	//k=4) a b c d 두번째 원소 b. b보다 작은거 1개 큰거 2개.
	// 
	for (int i = 0; i < n - 1; i++) {
		if (vec[i] <= vec[i + 1]) {
			cout << "YES\n";
			return 0;
		}	
	}
	for (int i = 0; i < n - 2; i++) {
		if ((vec[i] <= vec[i + 1] && vec[i + 1] <= vec[i + 2]) || (vec[i] >= vec[i + 1] && vec[i + 1] >= vec[i + 2])) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	
}