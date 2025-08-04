#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    bool mul = false;
    int d = common[1] - common[0];
    for (int i = 2; i < common.size(); i++){
        if (common[i]-common[i-1] != d){
            mul = true;
            d = common[1]/common[0];
            break;            
        }
    }
    if (mul) return common.back() * d;
    else return common.back() + d;
}