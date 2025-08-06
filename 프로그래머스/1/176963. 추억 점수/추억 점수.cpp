#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> umap;
    for (int i=0; i<name.size(); i++){
        umap[name[i]] = yearning[i];
    }
    
    for (int i=0; i<photo.size(); i++){
        int score = 0;
        for (int j=0; j<photo[i].size(); j++){
            score += umap[photo[i][j]];
        }
        answer.push_back(score);
    }
    return answer;
}