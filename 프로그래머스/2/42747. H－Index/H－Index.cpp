#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    int n = citations.size();
    for (int i=0; i<n; i++){
        if (citations[i] >= i+1) answer++;
        else break;
    }
    return answer;
}