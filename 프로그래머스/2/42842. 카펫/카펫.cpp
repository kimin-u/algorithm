#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a,b;
    int total = brown+ yellow;
    for (a=1; a< total; a++){
        for (b=1; b<total; b++){
            if (a*b == yellow && (a+2)*(b+2) == total ){
                return {b+2, a+2};
            }
        }
    }
    
    return answer;
}