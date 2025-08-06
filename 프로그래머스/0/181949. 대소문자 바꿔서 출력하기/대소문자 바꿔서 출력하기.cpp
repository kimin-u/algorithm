#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void) {
    string str;
    cin >> str;
    for (auto c : str){
        if (isupper(c)){
            cout<<(char)tolower(c);
        }
        else {
            cout<<(char)toupper(c);
        }
    }
    return 0;
}