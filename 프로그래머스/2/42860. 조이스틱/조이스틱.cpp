#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    string tmp = "";
    
    vector<int> tofixlist;
    for (int i=0; i<n; i++){
        tmp+= 'A';
        if (name[i] != 'A'){
            tofixlist.push_back(i);
        }
    }
    
    if (!tofixlist.empty()) {
        int m = tofixlist.size();
        // k=0: 전부 왼쪽 wrap만, k=m: 전부 오른쪽만
        int minMove = min(tofixlist[m-1], n - tofixlist[0]);

        for (int k = 1; k < m; k++) {
            int rightPart = tofixlist[k-1];       // 0 -> 오른쪽으로 여기까지
            int leftPart  = n - tofixlist[k];     // 0 -> wrap으로 여기까지
            minMove = min(minMove, min(2*rightPart + leftPart, rightPart + 2*leftPart));
        }
        answer += minMove;
    }
    
    
        
    for (int i=0; i<n; i++){
        //tmp[i] 를 수정하기
        char cur = tmp[i];
        char goal = name[i];
        
        if (cur == goal){ // 이미 같은 경우 
            continue;
        }
        
        int curidx = cur - 'A';
        int goalidx = goal - 'A';
        
        
        if (goalidx <= 13){
            answer += (goalidx-curidx);
        }
        else {
            answer += (26-goalidx);
        }
    }
    
    return answer;
}