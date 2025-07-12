#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> umap;
string solution(vector<string> participant, vector<string> completion) {
    //participant : 참여한 선수들 이름 배열
    //completion : 완주한 선수들 이름 배열
    string answer = "";
    int n = participant.size();
   
    for (int i=0; i<n; i++){
        umap[participant[i]]++;
    }
    for (int j=0; j<n-1; j++){
        umap[completion[j]]--;
    }
    
    for (auto& pair : umap) {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }
    
    return answer;
}