#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

string digital_logic;
int K, M;

ll stringtoll(string str){
    ll ret=0;

    int mul = 1;
    for (int i=str.length()-1;  i>=0; i--)
    {
        ret += str[i] * mul;
        mul*=2;
    }

    return ret;
}

int main() {
    cin >> digital_logic;
    cin >> K >> M;

    // Please write your code here.
    int answer = 0;
    unordered_map<int, int> umap;
    string pivot;
    ll val;
    for (int i=0; i<digital_logic.length() - K; i++){
        pivot = "";
        for (int j=i; j<i+K; j++){
            pivot += digital_logic[j];
        }

        val = stringtoll(pivot);


        umap[val]++;
    }

    for (auto &u: umap){
        if (u.second >= M){
            answer=1;
            break;
        }
    }

    cout<<answer;

    return 0;
}
