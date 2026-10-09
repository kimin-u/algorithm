#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

struct object{
    int id;
    int r; //좌상단 좌표 {r,c} 
    int c;
    int h; //직사각형 높이
    int w; //직사각형 너비
    int fullk;
    int k;
    bool status = true;
    bool moved = false;
};

int l,n,q;
int answer = 0;

vector<vector<int>> graph;
vector<vector<int>> objgraph;
vector<int> visited;
unordered_map<int, object> umap;

vector<int> di = {-1,0,1,0}; //상 우 하 좌
vector<int> dj = {0,1,0,-1};

bool can_move (int idx, int d){
    visited[idx] = 1;
    //// {ni, nj}를 좌상단으로 하는 h x w의 다음 직사각형에 벽이 존재하는가?
    object &obj = umap[idx];

    if (obj.status == false) return false;

    int ci = obj.r;
    int cj = obj.c;

    ci += di[d];
    cj += dj[d];

    if (ci <= 0 || ci + obj.h -1 > l || cj <= 0 || cj + obj.w -1> l) return false;


    for (int a = ci; a < ci + obj.h; a++){
        for (int b = cj; b < cj + obj.w; b++){
            if (graph[a][b] == 2){
                //벽이 있으면? 
                return false;
            }
        }
    }

    // TODO.
    //다음 객체에 대한 중복 체크가 있을 수 있는지 확인할 것. 코드 논리 확인
    for (int a = ci; a < ci + obj.h; a++){
        for (int b = cj; b < cj + obj.w; b++){
            if (objgraph[a][b] != 0 && objgraph[a][b] != idx  && !visited[objgraph[a][b]]) {
                //객체가 또 있으면? 걔도 밀어야함
                int nextidx = objgraph[a][b];
                bool tmpflag = can_move(nextidx, d);
                if (!tmpflag) return false;
            }
        }
    }

    return true;

}

void real_move(int idx, int d){
    object &obj = umap[idx];

    if (obj.status == false) return ;

    int ci = obj.r;
    int cj = obj.c;

    //ci cj를 한칸 옮기기 전에 -> 기존 objgraph에서 차지하고 있던 영역을 없애줘야함 
    for (int a = ci; a < ci + obj.h; a++){
        for (int b = cj; b < cj + obj.w; b++){
            objgraph[a][b] = 0;
        }
    }

    ci += di[d];
    cj += dj[d];  // {ci, cj} 는 한칸 이동한 좌상단 좌표임. 
    obj.r = ci;
    obj.c = cj;
    obj.moved = true;
    
    for (int a = ci; a < ci + obj.h; a++){
        for (int b = cj; b < cj + obj.w; b++){
            if (objgraph[a][b] != 0 && objgraph[a][b] != idx){

                //객체가 또 있으면? 걔도 옮겨야 함.
                int nextidx = objgraph[a][b];
                real_move(nextidx, d);
            }
            // 객체의 존재 여부랑 상관없이 objgraph 그래프 갱신이 필요하긴 함. 
            objgraph[a][b] = obj.id;
        }
    }


    // //DEBUG
    // cout<<"REAL MOVE : (IDX) "<< idx << '\n';
    // for (int i=1; i<=l; i++){
    //     for (int j =1; j<=l; j++){
    //         cout<<objgraph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

void move_obj(int idx, int d){

    //idx번 기사를 d 방향으로 움직이게 하기
    // 상 우 좌 하  (0, 1, 2, 3);
    object &obj = umap[idx];

    //이미 사라진 경우
    if (obj.status == false) return ;

    visited.assign(n + 1, 0);   

    bool flag = can_move(idx, d);

    if (!flag) return ;


    //meetwall이 true 면 그냥 return 해서 종료된거고
    // 그게 아닌 경우는 아래에서 구현
    // 한칸 씩 이동 시키면서 
    // 일단 최종적으로 옮겨진 최종 그래프를 만들어 (그래프 갱신 ) -> 이후에 값을 계산하자.
    real_move(idx, d);

    // //DEBUG
    // cout<<"이동 끝 objgraph :\n";
    // for (int i=1; i<=l; i++){
    //     for (int j =1; j<=l; j++){
    //         cout<<objgraph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    //최종 그래프를 획득했음. -> 계산 해야함 지금 idx 에서는 대미지 합산 안하고 
    for (int a = 1; a<=l; a++){
        for (int b = 1; b <= l; b++){
            if (objgraph[a][b] == 0) continue;
            if (objgraph[a][b] == idx) continue;
            else {
                object &tmp = umap[objgraph[a][b]];
                if (tmp.status == false) continue;
                if (tmp.moved == false) continue;
                
                if (graph[a][b] == 1){
                    tmp.k--;
                }
                if (tmp.k<= 0){
                    tmp.status = false;
                    for (int tmpa = tmp.r; tmpa < tmp.r + tmp.h; tmpa++){
                        for (int tmpb = tmp.c; tmpb < tmp.c + tmp.w; tmpb++){
                            objgraph[tmpa][tmpb] = 0;
                        }
                    }
                }
            }
        }
    }

    for (auto &u : umap){
        u.second.moved = false;
    }





}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>l>>n>>q;
    graph.assign(l+1, vector<int> (l+1, 0));
    objgraph.assign(l+1, vector<int> (l+1, 0));

    for (int i=1; i<=l; i++){
        for (int j=1; j<=l; j++){
            cin>>graph[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        object obj;
        obj.id = i;
        cin>>obj.r>>obj.c>>obj.h>>obj.w>>obj.k;
        obj.fullk = obj.k;
        umap[obj.id] = obj;

        for (int a = obj.r; a < obj.r + obj.h; a++){
            for (int b = obj.c; b < obj.c + obj.w; b++){
                objgraph[a][b] = obj.id;
            }
        }
    }

    // //debug.
    // for (int i=1; i<=l; i++){
    //     for (int j =1; j<=l; j++){
    //         cout<<objgraph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //simulation
    while (q--){
        int idx, d;
        cin>>idx>>d;

        visited.assign(n+1 , 0);

        move_obj(idx, d);

        
    }

    for (auto &u : umap){
        if (u.second.k <= 0) continue;
        answer += (u.second.fullk - u.second.k);
    }


    cout<<answer;

    return 0;
}