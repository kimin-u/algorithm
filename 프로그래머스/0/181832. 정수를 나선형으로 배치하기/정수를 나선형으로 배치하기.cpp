#include <string>
#include <vector>

using namespace std;

vector<int> di = {0,1,0,-1};
vector<int> dj = {1,0,-1,0};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    //4 3 3 2 2 1 1 까지 가면 끝.
    if (n == 1) return {{1}};

    int i = 0;
    int j = 0;
    int cnt = n-1;
    
    //initialize 
    int value = 1;
    for (int ppp=0; ppp<n; ppp++){
        answer[i][j] = value++;
        j++;
    }
    j--;
    int dir = 1;
    int tmp_cnt=0;
    int ttmp_cnt = 0;
    while (true){
        i = i + di[dir];
        j = j + dj[dir];
        answer[i][j] = value++;
        tmp_cnt++;
        
        if (tmp_cnt == cnt){
            ttmp_cnt++;
            tmp_cnt=0;
            dir = (dir+1)%4;
        }
        if (ttmp_cnt == 2){
            ttmp_cnt = 0;
            cnt--;
        }
        if (value == n*n + 1) break;
    }
    
         
    return answer;
}