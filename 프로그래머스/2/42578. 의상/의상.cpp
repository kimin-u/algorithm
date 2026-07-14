#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> umap;
    
    for (auto& cloth : clothes){
        umap[cloth[1]]++;
    }
    
    answer = 1;
    for (auto &u : umap){
        answer*= (u.second+1);
    }
    answer--;
    
    return answer;
}