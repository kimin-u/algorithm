#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct volcano {
    int r;
    int c;
    int p;
    int magma;
    bool status = false;
};

int n, m, k;
vector<vector<int>> graph; // 0: 빈공간, 1: 산호초
vector<pair<int, int>> turtles; //거북이 위치 정보
vector<volcano> volcanos; //화산 위치+임계값 정보
vector<int> answer;
vector<vector<int>> magma_map;

vector<int> di = {0,1,0,-1};
vector<int> dj = {1,0,-1,0};

void move_turtles(int idx, int turn){
    int r = turtles[idx].first;
    int c = turtles[idx].second;

    if (r== -1 && c== -1) return; //이미 완주하거나 화석이 된 거북이.

    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    //역방향 그래프 탐색 이후 거북이 옮기기. 
    dist[n-1][n-1] = 0;
    queue<pair<int, int>> q;
    q.push({n-1,n-1});
    
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        if (ci == r && cj == c){
            break;
        }

        for (int d = 0; d<4; d++){
            int ni = ci + di[d];
            int nj = cj + dj[d];

            if (ni<0 || ni>=n || nj < 0 || nj >= n) continue;
            
            //산호초, 다른 거북, 화석으로 인해 도달이 가능한지를 체크하긴 해야함. 
            //산호초 체크, 화석 체크 --> 화석은 graph 바꾸는 경우를 구현해야함
            if (graph[ni][nj] != 0) continue;

            //다른 거북 체크
            int flag = true;
            for (int i=0; i<m; i++){
                if (i== idx) continue;
                int otheri = turtles[i].first;
                int otherj = turtles[i].second;

                if (ni == otheri && nj == otherj){
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            

            if (dist[ni][nj] > dist[ci][cj] + 1){
                dist[ni][nj] = dist[ci][cj] + 1;
                q.push({ni,nj});
            }
        }
    }

    //dist[r][c]를 통해서 도달 가능성 여부 판단 및 이동.
    if (dist[r][c] != 1e9){
        int pivot = dist[r][c];

        for (int d = 0; d<4; d++){
            int ni = r + di[d];
            int nj = c + dj[d];
            if (ni<0 || ni>=n || nj < 0 || nj >= n) continue;

            if (dist[ni][nj] == pivot - 1){
                turtles[idx].first = ni;
                turtles[idx].second = nj;
                break;
            }
        }

        if (turtles[idx].first == n-1 && turtles[idx].second == n-1){
            answer[idx] = turn;
            turtles[idx].first = -1;
            turtles[idx].second = -1;
        }

    }
}

void increase_magma(){
    for (auto &volcano : volcanos){
        int r = volcano.r;
        int c = volcano.c;
        volcano.magma += 10;
    }
}

void eruption(){
    //열기 전파.
    for (auto &volcano : volcanos){
        int r = volcano.r;
        int c = volcano.c;
        int p = volcano.p;
        bool flag = volcano.status;

        if (flag == true) continue;

        if (volcano.magma >= volcano.p){ 
            //분출 조건 달성.
            volcano.status = true;
            magma_map[r][c] += p;
            for (int d=0; d<4; d++){
                int ci = r;
                int cj = c;
                int cp = p;
                //각 방향별로 쭉 magma_map을 갱신해야할 것임. 
                while (true){
                   //종료조건은 분출값이 0이 되거나 산호초를 만나면 종료. -> 다른 방향으로 다시 분출 구현해야함. 
                    int ni = ci + di[d];
                    int nj = cj + dj[d];
                    int np = cp/2;

                    if (ni<0 || ni>=n || nj < 0 || nj >= n) break;

                    if (graph[ni][nj] == 1) break;

                    if (np == 0) break;

                    magma_map[ni][nj] += np;

                    ci = ni;
                    cj = nj;
                    cp = np;      
                }
            }
        }
    }

    //연쇄 반응
    while (true){
        bool continuous_eruption = false;

        for (auto &volcano : volcanos){
            int r = volcano.r;
            int c = volcano.c;
            int p = volcano.p;
            bool flag = volcano.status;

            if (flag == true) continue;

            if (magma_map[r][c] + volcano.magma >= volcano.p){ 
                //분출 조건 달성.
                volcano.status = true;
                continuous_eruption = true;
                for (int d=0; d<4; d++){
                    int ci = r;
                    int cj = c;
                    int cp = p;
                    //각 방향별로 쭉 magma_map을 갱신해야할 것임. 
                    while (true){
                    //종료조건은 분출값이 0이 되거나 산호초를 만나면 종료. -> 다른 방향으로 다시 분출 구현해야함. 
                        int ni = ci + di[d];
                        int nj = cj + dj[d];
                        int np = cp/2;

                        if (ni<0 || ni>=n || nj < 0 || nj >= n) break;

                        if (graph[ni][nj] == 1) break;

                        if (np == 0) break;

                        magma_map[ni][nj] += np;

                        ci = ni;
                        cj = nj;
                        cp = np;      
                    }
                }
            }
        }
        if (continuous_eruption == false){
            break;
        }
    }

    //거북이 화석화.
    for (int i=0; i<m; i++){
        int r= turtles[i].first;
        int c= turtles[i].second;

        if (r==-1 || c== -1) continue;

        if (magma_map[r][c] >= 20){
            turtles[i].first = -1;
            turtles[i].second = -1;
            graph[r][c] = 2;
        }
    }   
}

void clear_env(){   
    magma_map.assign(n, vector<int>(n,0));

    for (auto &volcano : volcanos){
        if (volcano.status == true){
            volcano.status = false;
            volcano.magma = 0;
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //input
    cin>>n>>m>>k;

    //initialize & input.
    graph.assign(n, vector<int>(n,0));
    magma_map.assign(n, vector<int> (n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    for (int i=0; i<m; i++){
        int r, c;
        cin>>r>>c;
        turtles.push_back({r,c});
    }

    for (int i=0; i<k; i++){
        int r, c, p;
        cin>>r>>c>>p;
        volcanos.push_back({r,c,p,0,false});
    }

    answer.assign(m, -1);

    //simulation 
    //while loop 1번 = 1개의 턴 
    //각 턴 -> 4개의 단계를 수행해야함

    for (int turn = 1; turn <=100; turn++){
        //1단계
        for (int i=0; i<m; i++){
            move_turtles(i, turn);
            if (turtles[i].first == n-1 && turtles[i].second == n-1){
            }

        }
        
        //2단계
        increase_magma();

        //3단계
        eruption();

        //4단계
        clear_env();

    }

    for (auto &a: answer){
        cout<<a<<'\n';
    }

    return 0;
}