#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);


	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		vector<vector<int>> vec(100, vector<int>(100, 0));

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> vec[i][j];
			}
		}

		int answer = -1;

		//행 합
		for (int i = 0; i < 100; i++) {
			int tmpsum = 0;
			for (int j = 0; j < 100; j++) {
				tmpsum += vec[i][j];
			}
			answer = max(answer, tmpsum);
		}

		//열 합
		for (int i = 0; i < 100; i++) {
			int tmpsum = 0;
			for (int j = 0; j < 100; j++) {
				tmpsum += vec[j][i];
			}
			answer = max(answer, tmpsum);
		}

		//우하향 대각
		int tmpsum = 0;
		for (int i = 0; i < 100; i++) {
			tmpsum += vec[i][i];
		}
		answer = max(answer, tmpsum);

		//좌하향 대각
		tmpsum = 0;
		for (int i = 0; i < 100; i++) {
			tmpsum += vec[i][99 - i];
		}

		answer = max(answer, tmpsum);

		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}