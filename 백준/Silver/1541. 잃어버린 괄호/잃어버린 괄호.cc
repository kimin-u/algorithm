#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	int result = 0;
	string tmp = "";

	int size = str.size();
	int minus = 0;
	for (int i = 0; i <= size; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] =='\0') {
			if (!minus) 
				result += stoi(tmp);
			else
				result -= stoi(tmp);
			if (str[i] == '-')
				minus = 1;
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	cout << result;
}