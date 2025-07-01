#include <iostream>
#include <vector>

using namespace std;

long long int n;
vector<long long int> length;
vector<long long int> price;

unsigned long long int result = 0;

int main(void)
{
	cin >> n;
	length.assign(n - 1, 0);
	price.assign(n, 0);
	for (int i = 0; i < n - 1; i++) {
		cin >> length[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> price[j];
	}

	long long int minprice = price[0];

	result += length[0] * price[0];

	for (int i = 1; i < n - 1; i++) {
		if (minprice > price[i]) {
			minprice = price[i];
		}
		result += minprice * length[i];
	}
	
	cout << result;
	return 0;
}