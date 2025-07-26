#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    cout << fixed << setprecision(10) << static_cast<double>(a) / b;
    
    return 0;
}