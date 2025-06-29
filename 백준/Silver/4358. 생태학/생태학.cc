#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	int total_cnt = 0;

	string name;
	while (getline(cin, name)) {
		total_cnt++;
		m[name]++;
	}

	for (auto& p : m) {
		double portion = (double)p.second / (double)total_cnt;
		printf("%s %.4f\n", p.first.c_str(), portion*100);
	}


}