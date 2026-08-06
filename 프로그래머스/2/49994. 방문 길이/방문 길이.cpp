#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> visited;


vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,1,-1};

int solution(string dirs) {
    int answer = 0;
    
    visited.assign(21, vector<int>(21,0));
    unordered_map<char, int> umap;
    umap['U']= 0;
    umap['D']= 1;
    umap['R']= 2;
    umap['L'] = 3;
    
    int ci = 5;
    int cj = 5;
    for (auto &d: dirs){
        int k = umap[d];
        
        int ni = ci + di[k];
        int nj = cj + dj[k];
        
        if (ni < 0 || ni > 10 || nj < 0 || nj > 10) continue;
        
        int si = ci + ni;
        int sj = cj + nj;
        
        if (visited[si][sj] == 0){
            visited[si][sj] = 1;
            answer++;
        }
        ci = ni; cj = nj;
    }
    
    return answer;
}