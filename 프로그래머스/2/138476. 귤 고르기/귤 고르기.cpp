#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> umap;
    for (auto &t : tangerine){
        umap[t]++;
    }
    
    vector<int> vec;
    for (auto &u :umap){
        vec.push_back(u.second);
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for (int i=0; i<vec.size(); i++){
        if (k<=0) break;
        k-=vec[i];
        answer++;
    }
    return answer;
}