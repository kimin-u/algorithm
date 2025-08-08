#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    unordered_map<int, int> umap;
    
    for (auto a: array){
        umap[a]++;
    }
    int maxv=0;
    
    for (auto u: umap){
        int v = u.second;
        maxv = max(maxv, v);
    }
    vector<int> vec;
    for (auto u:umap){
        if (u.second == maxv)
            vec.push_back(u.first);
    }
    
    if (vec.size() > 1) answer= -1;
    else answer = vec[0];
    return answer;
}