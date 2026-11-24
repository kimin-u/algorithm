#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> visited;
int answer = -1;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int n, m;
int ti, tj;
int si, sj;


void bfs(vector<string> &graph){
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = 0;
    
    int ni, nj;
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        if (ci == ti && cj == tj) {
            answer = visited[ci][cj];
            break;
        }
        
        for (int k =0; k<4; k++){
            //ni, nj는 최대한 이동시키는게 핵심.
            //k는 방향을 의미함.
            int tmpi = ci;
            int tmpj = cj;
            while (true){
                ni = tmpi + di[k];
                nj = tmpj + dj[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    break;
                }
                if (graph[ni][nj] == 'D'){
                    break;
                }
                tmpi = ni;
                tmpj = nj;                
            }
            
            if (visited[tmpi][tmpj] > visited[ci][cj] + 1){
                visited[tmpi][tmpj] = visited[ci][cj] + 1;
                q.push({tmpi, tmpj});
            }
        }
    }
}

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    visited.assign(n, vector<int>(m, 1e9));
    
    
    for (int i=0; i<n; i++){
        for (int j =0; j<m; j++){
            if (board[i][j]=='R'){
                si = i; sj = j;
            }
            else if (board[i][j] == 'G'){
                ti = i; tj = j;
            }
        }
    }
    
    bfs(board);
    
    return answer;
}