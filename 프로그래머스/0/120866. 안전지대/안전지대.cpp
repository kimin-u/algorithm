#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> di = {-1,-1,-1,0,0,1,1,1};
vector<int> dj = {-1,0,1,-1,1,-1,0,1};
int n,m;

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 1){
                for (int k=0; k<8;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni <0 || ni>=n || nj<0 || nj>=m) continue;
                    
                    if (board[ni][nj] == 0) board[ni][nj] =2;
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == 0)
                answer++;
        }
    }
    return answer;
}