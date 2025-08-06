#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> umap;
    for (int i=0; i<players.size(); i++){
        umap[players[i]] = i;
    }
    
    for (int i=0; i<callings.size(); i++){
        int idx = umap[callings[i]];
        int prev_idx = idx-1;
        
        // players.erase(players.begin() + idx);
        // players.insert(players.begin() + prev_idx, callings[i]);
        swap(players[idx], players[prev_idx]);

        umap[players[idx]] = idx;
        umap[players[prev_idx]] = prev_idx;
    }
    return players;
}