#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi(int src, int tmp, int dest, int n){
    if (n==1) 
        answer.push_back({src, dest});
    else{
        hanoi(src, dest,tmp,n-1);
        answer.push_back({src,dest});
        hanoi(tmp,src,dest,n-1);
    }
}
vector<vector<int>> solution(int n) {
    hanoi(1,2,3,n);
    return answer;
}