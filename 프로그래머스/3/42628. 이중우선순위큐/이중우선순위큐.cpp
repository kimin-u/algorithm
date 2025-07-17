#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    unordered_map<int, int> umap;
    
    for (auto operation : operations){
        if (operation[0] == 'I'){
            string num="";
            for (int i=2; i<operation.size(); i++){
                num+=operation[i];
            }
            int n = stoi(num);
            max_pq.push(n);
            min_pq.push(n);
            umap[n]++;
        }
        else if (operation[0] == 'D'){
            int n = operation[2];
            if (n=='1'){
                while (!max_pq.empty() && umap[max_pq.top()]==0) max_pq.pop();
                if (max_pq.empty()) continue;
                int tmp = max_pq.top(); max_pq.pop();
                if (umap[tmp] > 0){
                    umap[tmp]--;
                }
            }
            else if (n=='-'){
                while (!min_pq.empty() && umap[min_pq.top()]==0) min_pq.pop();
                if (min_pq.empty()) continue;
                int tmp = min_pq.top(); min_pq.pop();
                if (umap[tmp] > 0){
                    umap[tmp]--;
                }
            }
            
        }
    }
    
    while (!max_pq.empty() && umap[max_pq.top()] == 0) max_pq.pop();
    while (!min_pq.empty() && umap[min_pq.top()] == 0) min_pq.pop();
    
    if (max_pq.empty() || min_pq.empty()){
        return {0, 0};
    }
    else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    return answer;
}