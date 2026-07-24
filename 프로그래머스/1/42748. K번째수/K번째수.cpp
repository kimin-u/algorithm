#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto &command :commands){
        int i = command[0];
        int j = command[1];
        int k = command[2];
        vector<int> tmp;
        for (int idx = i-1; idx<=j-1; idx++){
            tmp.push_back(array[idx]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}