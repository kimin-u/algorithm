#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int h, w;
vector<vector<char>> graph;
vector<vector<int>> visited;

vector<int> di = {0,1,0,-1}; //좌 하 우 상 
vector<int> dj = {-1,0,1,0}; //좌 하 우 상
char dir_char[4] = {'<', 'v', '>', '^'};

int checkaround(int i, int j){
    int ci = i;
    int cj = j;

    int cnt = 0; 
    int startdir = -1;
    for (int k =0; k<4; k++){
        int ni = ci + di[k];
        int nj = cj + dj[k];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        
        if (graph[ni][nj] == '#') {
            cnt++;
            startdir = k; 
        }
    }
    
    if (cnt == 1) return startdir;
    return -1;
}

int checknextdir(int i, int j){
    int ci = i;
    int cj = j;

    for (int k = 0; k<4; k++){
        int ni = ci + di[k];
        int nj = cj + dj[k];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        
        if (graph[ni][nj] != '#') continue;
        if (visited[ni][nj] == 1) continue;

        return k;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin>>h>>w;
    graph.assign(h, vector<char>(w, ' '));
    visited.assign(h, vector<int>(w, 0));

    struct ans{
        int i; 
        int j;
        int dir;
        string route;
    };
    vector<struct ans> answer;

    vector<pair<int, int>> startpoints;
    
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin>>graph[i][j];
        }
    }

    for (int i=h-1; i>=0; i--){
        for (int j=w-1; j>=0; j--){
            string route = "";
            if (graph[i][j] == '#'){
                int startdir = checkaround(i,j); // 0,1,2,3 좌,하,우,상
                if (startdir == -1) continue;

                visited[i][j] = 1;
                int ci = i;
                int cj = j;
                int firstdir = startdir;
                

                while (true){
                    route += 'A';
                    int ni = ci + di[startdir];
                    int nj = cj + dj[startdir];
                    int nni = ni + di[startdir];
                    int nnj = nj + dj[startdir];
                    
                    visited[ni][nj] = 1;
                    visited[nni][nnj] = 1;
                    
                    ci = nni; cj = nnj;

                    int nextdir = checknextdir(ci, cj);
                    if (nextdir == -1) break;

                    if (startdir == nextdir) continue;
                    if ((startdir+1)%4 ==nextdir) {
                        route+='L';
                        startdir = nextdir;
                    }
                    else if ((startdir+3)%4 == nextdir){
                        route += 'R';
                        startdir = nextdir;
                    }

                }
                
                cout<<i+1<<" "<<j+1<<'\n';
                cout<<dir_char[firstdir]<<'\n';
                cout<<route<<'\n';
                return 0;
            }
        }
    }


    return 0;
}