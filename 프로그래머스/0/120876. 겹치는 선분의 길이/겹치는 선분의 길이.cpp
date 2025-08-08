#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<int> tmp(201,0);
    for (auto line :lines){
        for (int i=line[0]; i<line[1]; i++){
            tmp[i+100]++;
        }
    }
    for (auto t : tmp){
        if (t>=2) answer++;
    }
    return answer;
}