#include <iostream>
#include <string>
#include <stack> 
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string str; cin >> str;
	stack<double> st;
	double num;
	
	vector<double> alphabet;
	for (int i = 0; i < n; i++) {
		cin >> num;
		alphabet.push_back(num);
	}

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			st.push(alphabet[str[i] - 'A']);
		}
		else {
			double tmp1 = st.top(); st.pop();
			double tmp2 = st.top(); st.pop();
			double result;
			switch (str[i]) {
				case '+':
					result = tmp2 + tmp1;
					st.push(result);
					break;
				case '-':
					result = tmp2 - tmp1;
					st.push(result);
					break;
				case '*':
					result = tmp2 * tmp1;
					st.push(result);
					break;
				case '/':
					result = tmp2 / tmp1;
					st.push(result);
					break;
			}
		}
	}

	printf("%.2f\n", st.top());
}