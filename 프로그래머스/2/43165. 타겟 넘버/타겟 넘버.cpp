#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(vector<int> numbers, int target, int i, int sum){
    if (i == numbers.size()){
        if (sum == target){
            cnt++;
        }
        return;
    }
    
    dfs(numbers, target, i+1, sum+numbers[i]);
    dfs(numbers, target, i+1, sum-numbers[i]);
}
int solution(vector<int> numbers, int target) {    
    dfs(numbers, target, 0, 0);
    return cnt;
}