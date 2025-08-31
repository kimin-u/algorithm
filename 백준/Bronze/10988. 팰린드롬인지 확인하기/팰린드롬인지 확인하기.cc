#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    stack<char> stack;
    string palin;

    cin >> str;

    for (int i=0; i<str.length(); i++)
        stack.push(str[i]);
    while (!stack.empty()) {
        palin.push_back(stack.top());
        stack.pop();
    }

    if (str.compare(palin)==0)
        cout<<"1";
    else
        cout<<"0";
    
    return 0;
}
