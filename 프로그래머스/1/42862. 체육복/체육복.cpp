#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> realLost, realReserve;
    for (int l : lost)
        if (find(reserve.begin(), reserve.end(), l) == reserve.end())
            realLost.push_back(l);
    for (int r : reserve)
        if (find(lost.begin(), lost.end(), r) == lost.end())
            realReserve.push_back(r);
    lost = realLost;
    reserve = realReserve;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int lostcnt = lost.size();
    vector<int> used(n+1,0);
    for(int i=0; i<reserve.size(); i++){
        int enough = reserve[i];
        int prev = -1;
        int next = -1;
        if (enough != 1){
            prev = enough -1;
        }
        if (enough != n){
            next = enough + 1;
        }
        
        for (int j=0; j<lost.size(); j++){
            int need = lost[j];
            if (need == prev){
                if (used[prev] == 0){
                    used[prev] = 1;
                    lostcnt--;
                    break;
                }
            } 
            else if (need == next){
                if (used[next] == 0){
                    used[next] = 1;
                    lostcnt--;
                    break;
                }
            }
        }
    }
    lostcnt = max(0, lostcnt);
    answer = n - lostcnt;
    return answer;
}