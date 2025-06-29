#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(void)
{
    int n, m ;
    cin >> n >> m;
    int cnt =0;

    set<string> s;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        s.insert(str);
    }

    for(int i=0; i<m; i++){
        cin >> str;
        if(s.find(str)!= s.end()) cnt++;
    }

    cout<<cnt;

    return 0;

}
