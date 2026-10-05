#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

struct area{
    int id;
    int starti;
    int startj;
    int surface=0;

    vector<pair<int, int>> points;
};

bool compare(area a, area b){
    if (a.surface == b.surface) return a.id < b.id;
    return a.surface > b.surface;
}

int n, q;
vector<vector<int>> graph;
vector<vector<int>> visited;

int area_bfs(int i, int j, int val){
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i,j});

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k = 0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (!visited[ni][nj] && graph[ni][nj] == val){
                visited[ni][nj] = 1;
                q.push({ni,nj});
            }
        }
    }

    return 1;
}

void add_graph(int r1, int c1, int r2, int c2, int val){
    for (int i = r1; i<r2; i++){
        for (int j = c1 ; j <c2; j++){
            graph[i][j] = val;
        }
    }
}

void remove_graph(int val){
    vector<int> vec(val+1, 0);

    visited.assign(n, vector<int>(n,0));
    for (int i=0; i<n; i++){
        for (int j =0; j<n; j++){
            //방문 안한거면 bfs돌리고 각 val 별로 영역이 몇개로 나뉘었는지를 count 추가 
            if (!visited[i][j] && graph[i][j] != 0){
                int tmp = area_bfs(i,j, graph[i][j]);
                vec[graph[i][j]] += tmp;
            }
        }
    }

    //vec 순회하면서 2이상이면 -> 해당 영역 다 삭제시켜야 함.
    for (int i=0; i<vec.size(); i++){
        if (vec[i] >= 2){
            for (int a=0; a<n; a++){
                for( int b= 0; b<n; b++){
                    if (graph[a][b] == i){
                        graph[a][b] = 0;
                    }
                }
            }
        }
    }   
}

vector<int> find_neighbor_bfs(int i, int j, int val, int idx){
    visited.assign(n, vector<int>(n,0));

    visited[i][j] =1;
    queue<pair<int, int>> q;
    q.push({i,j});

    vector<int> retvec;
    
    while (!q.empty()){
        int ci = q.front().first;   
        int cj = q.front().second;
        q.pop();

        for (int k =0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (!visited[ni][nj]){
                visited[ni][nj] = 1;
                if (graph[ni][nj] == val){
                    q.push({ni, nj});
                }
                else{
                    if (graph[ni][nj] > val){
                        retvec.push_back(graph[ni][nj]);
                    }
                }
            }
        }
    }

    sort(retvec.begin(), retvec.end());
    retvec.erase(unique(retvec.begin(), retvec.end()), retvec.end());
    
    return retvec;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //input
    cin>>n>>q;

    graph.assign(n, vector<int> (n, 0));

    //simulation
    for (int idx=1; idx<=q; idx++){
        int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;

        //미생물 투입
        add_graph(r1,c1,r2,c2, idx);
        remove_graph(idx);
        
        //배양 용기 이동
        vector<area> vec(idx+1);
        for (int i=0; i<n; i++){
            for (int j =0; j<n; j++){
                if (graph[i][j] != 0){
                    int val = graph[i][j];
                    
                    if (vec[val].surface == 0){
                        vec[val].starti=i;
                        vec[val].startj=j;
                    }
                    vec[val].id = val;
                    vec[val].surface++;
                    int tmpi = i-vec[val].starti;
                    int tmpj = j-vec[val].startj;
                    vec[val].points.push_back({tmpi, tmpj});

                    graph[i][j] = 0;
                }
            }
        }

        sort(vec.begin(), vec.end(), compare);

        for (int v =0; v < vec.size(); v++){
            //해당 미생물을 옮길 수 있는 지 그래프를 순회하면서 체크해야함 .
            bool flag = true;
            int val = vec[v].id;
            vector<pair<int, int>> &curpoints = vec[v].points;
            for (int i =0; i<n; i++){
                int tmpflag = false;
                for (int j =0; j<n; j++){
                    flag = true;
                    //i,j가 시작점이 되는 곳에 해당 미생물 모든 points를 옮길 수 있는지 확인.
                    for (int p=0; p<curpoints.size(); p++){
                        int tmpi = curpoints[p].first;
                        int tmpj = curpoints[p].second;

                        int ni = i + tmpi;
                        int nj = j + tmpj;

                        if (ni <0 || ni >=n || nj <0 || nj>=n) { //범위 넘어가서 해당 startpoint에는 못넣는 경우임.
                            flag = false;
                            break;
                        }

                        if (graph[ni][nj] != 0){
                            flag = false;
                            break;
                        }
                    }
                    if (flag){
                        //i,j를 시작으로 넣을 수 잇는경우 
                        for (int p=0; p<curpoints.size(); p++){
                            int tmpi = curpoints[p].first;
                            int tmpj = curpoints[p].second;

                            int ni = i + tmpi;
                            int nj = j + tmpj;

                            graph[ni][nj] = val;
                        }
                        tmpflag = true;
                        break;
                    }
                }
                // i,j에서 이미 해당 미생물을 넣은 경우 처리 break;
                if (tmpflag){
                    break;
                }
                // 못넣었으면 계속 loop 돌아야 겠지 ㅇㅇ
            }
            // 미생물을 못넣었으면 surface 라던지 값 갱신의 필요성 ?? 확인해보기 
        }


        //실험 결과 기록
        vector<vector<int>> neighbor (idx+1); // 이웃이 누구인지를 저장할 벡터임/
        vector<int> checked(idx+1, 0);
        
        for (int i=0; i<n; i++){
            for (int j =0; j<n; j++){
                if (!checked[graph[i][j]] && graph[i][j] != 0){
                    checked[graph[i][j]] = 1;
                    vector<int> tmp_neighbor = find_neighbor_bfs(i,j, graph[i][j], idx);
                    neighbor[graph[i][j]]= tmp_neighbor;
                }
            }
        }

        int answer = 0;
        for (int i=1; i<neighbor.size(); i++){
            vector<int> tmp = neighbor[i];
            int pivot;
            vector<int> s_tmp;
            for (int v =0; v<vec.size(); v++){
                if (vec[v].id == i){
                    pivot = vec[v].surface;
                    continue;
                }
                for (int t=0; t<tmp.size(); t++){
                    if (vec[v].id == tmp[t]){
                        s_tmp.push_back(vec[v].surface);
                    }
                }
            }

            for (int t =0; t<s_tmp.size(); t++){
                answer += (pivot * s_tmp[t]);
            }

        }

        cout<<answer<<'\n';


    }
    return 0;
}