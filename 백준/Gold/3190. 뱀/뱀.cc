#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n,k,l;
int ci=0; 
int cj=0;
int len = 1; 
int t = 0;
vector<int> di = {-1,0,1,0}; //상우하좌
vector<int> dj = {0,1,0,-1}; 
int dir = 1;
vector<vector<int>> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    graph.assign(n, vector<int>(n,0));
    for (int i=0; i<k; i++){
        int ai,aj; cin>>ai>>aj;
        graph[ai-1][aj-1] = 1;
    }    

    deque<pair<int,int>>dq;
    dq.push_back({0,0});
    

    cin>>l;
    //todo : queue를 사용해서 뱀의 이동경로를 추적해야함.
    for (int i=0; i<l; i++){
        int a; char rot; cin>>a>>rot;
        //a-t 만큼 현재 dir으로 이동해야함
        int tmp = t;
        for (int cnt = 0; cnt < a-tmp; cnt++){
            t++;
            int ni = ci + di[dir];
            int nj = cj + dj[dir];
            // cout<<t<<" "<< ni<<", "<<nj<<'\n';
            if (ni <0 || ni >=n || nj<0 ||nj>=n) {
                cout<<t; 
                return 0;
            }
            // q에 넣기 전에 자신의 몸과 부딪히는 지 검사 
            for (auto p: dq){
                if (p.first == ni && p.second == nj) {
                    cout<<t;
                    return 0;
                }
            }

            dq.push_back({ni,nj});
            if (graph[ni][nj] != 1){
                dq.pop_front();
            }
            else {
                graph[ni][nj] =0;
            }
            ci = ni; cj = nj;
        }
        if (rot == 'D'){
            dir = (dir+1)%4;
        }
        else {
            dir = (dir+3)%4;
        }
    }

    while (true){
        t++;
        int ni = ci + di[dir];
        int nj = cj + dj[dir];
        if (ni <0 || ni >=n || nj<0 ||nj>=n) {
            cout<<t; 
            return 0;
        }
        // q에 넣기 전에 자신의 몸과 부딪히는 지 검사 
        for (auto p: dq){
            if (p.first == ni && p.second == nj) {
                cout<<t;
                return 0;
            }
        }

        dq.push_back({ni,nj});
        if (graph[ni][nj] != 1){
            dq.pop_front();
        }
        else {
            graph[ni][nj] =0;
        }
        ci = ni; cj = nj;
    }
}