#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;

void bfs(string begin, string target, vector<string> words){
    int n_words = words.size();
    dist.assign(n_words, 1e9);
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty()){
        string cstring = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        for (int i=0; i<n_words; i++){
            //cstring 에서 words[i]로 변환하려면 몇개 바뀌어야 하는지 체크
            //다른 알파벳 개수 찾으면 됨
            int cnttochange=0;
            string tmpstring = words[i];
            for (int j =0; j<tmpstring.length(); j++){
                if (cstring[j] != tmpstring[j]){
                    cnttochange++;
                }
            }
            if (cnttochange != 1){
                continue;
            }
            
            //1개만 바꾸면 되는 경우 ㅇㅇ 
            if (dist[i] > cost + 1){
                dist[i] = cost + 1;
                q.push({tmpstring, dist[i]});
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool flag = false;
    int target_idx = -1;
    for (int i=0; i<words.size(); i++){
        if (target == words[i]){
            flag= true;
            target_idx =i;
            break;
        }
    }
    
    if (!flag) {
        return 0;
    }
    
    bfs(begin, target, words);
    
    return dist[target_idx];
}