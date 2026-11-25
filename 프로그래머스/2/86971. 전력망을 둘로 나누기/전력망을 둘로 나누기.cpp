#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


//송전탑 전선 정보를 바탕으로 두개로 나누기,
//두 송전탑 그룹의 개수가 비슷해지게 해야함. 
//각 엣지를 끊엇을 경우에 생기는 경우의 수를 완탐 해야함.

int answer = 1e9;

vector<int> visited;

int bfs(int n, int idx, vector<vector<int>> &wires, int i){
    //wires[idx]는 무시해야함.
    //i+1 번째 노드부터 시작.
    visited[i+1] =1;
    queue<int> q;
    q.push(i+1);
    int returnsize = 1;
    
    while (!q.empty()){
        int ci = q.front();
        q.pop();
        
        for (int wire =0; wire< wires.size(); wire++){
            if (wire == idx) continue;
            
            
            int ni;
            if (wires[wire][0] == ci) ni = wires[wire][1];
            else if (wires[wire][1] == ci) ni = wires[wire][0];
            else continue;

            
            if (!visited[ni]){
                visited[ni] = 1;
                q.push(ni);
                returnsize++;
            }
        }
    }
    
    return returnsize;
}

int solution(int n, int idx, vector<vector<int>> &wires){
    vector<int> groupsize(2,0);
    int groupidx = 0;
    for (int i=0; i<n; i++){
        if (!visited[i+1]){
            groupsize[groupidx] = bfs(n, idx, wires, i);
            groupidx++;            
        }
        if (groupidx > 2) return 1e9;
    }
    
    return abs(groupsize[0] - groupsize[1]);
}

int solution(int n, vector<vector<int>> wires) {    
    for (int i=0; i<wires.size(); i++){
        //i번째 wire를 제거했을때 생기는 각 그룹의 개수를 계산 -> 이거 차이의 최솟값을 갱신해야함.
        visited.assign(n+1, 0);
        answer = min(answer,solution(n, i, wires));
    }
    
    return answer;
}