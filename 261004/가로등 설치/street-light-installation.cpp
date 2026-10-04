#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct light{
    int x;
    int id;
    bool status;
    int prv = 0;
    int nxt = 0;
};

struct interval{
    int distance;
    int left;
    int right;
    int left_id;
    int right_id;
};

struct compare{
    bool operator() (interval a, interval b){
        if (a.distance == b.distance) return a.left > b.left;
        return a.distance < b.distance;
    }
};

int q,n,m;
unordered_map<int, light> umap;

int startpoint = 0;
int endpoint = 0;
priority_queue<interval, vector<interval>, compare> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;

    int op;
    while (q--){
        cin>>op;
        if (op == 100){
            cin>>n>>m;

            for (int i=1; i<=m; i++){
                //tmp initialize
                light tmp;
                tmp.id = i;
                cin>>tmp.x;
                tmp.status = true;
                tmp.prv = i-1;

                umap[tmp.id] = tmp;
                
                if (i==1){
                    startpoint = i;
                }
                else {
                    umap[i-1].nxt = i;

                    interval tmp_interval;

                    tmp_interval.distance = umap[i].x - umap[i-1].x;
                    tmp_interval.left = umap[i-1].x;
                    tmp_interval.right = umap[i].x;
                    tmp_interval.left_id = i-1;
                    tmp_interval.right_id = i;

                    pq.push(tmp_interval);
                }
                endpoint = i;
            }
        }

        else if (op == 200){
            light tmp;
            tmp.id = ++m;

            //pq기반으로 어디에 넣을지 고르고 
            interval tmp_interval;

            while (!pq.empty()){
                tmp_interval = pq.top(); pq.pop();
                if (umap[tmp_interval.left_id].status == true && umap[tmp_interval.right_id].status == true) break;
            }
            
            int mid = (tmp_interval.left + tmp_interval.right + 1) / 2;
        
            tmp.x = mid;
            tmp.status = true;
            tmp.prv = tmp_interval.left_id;
            tmp.nxt = tmp_interval.right_id;
            umap[tmp.id] = tmp;

            umap[tmp_interval.left_id].nxt = tmp.id;
            umap[tmp_interval.right_id].prv = tmp.id;

            //새로 생긴 가로등에 따른 사이 거리 정보 좌 우 업데이트
            interval leftside, rightside;
            leftside.distance = mid-tmp_interval.left;
            leftside.left = tmp_interval.left;
            leftside.right = mid;
            leftside.left_id = tmp_interval.left_id;
            leftside.right_id = tmp.id;

            rightside.distance = tmp_interval.right-mid;
            rightside.left =mid;
            rightside.right = tmp_interval.right;
            rightside.left_id = tmp.id;
            rightside.right_id = tmp_interval.right_id;

            pq.push(leftside);
            pq.push(rightside);           
        }

        else if (op == 300){
            int d; 
            cin>>d;

            int pid = umap[d].prv;
            int nid = umap[d].nxt;
            umap[d].status = false;

            
            if (pid) umap[pid].nxt = umap[d].nxt;
            if (nid) umap[nid].prv = umap[d].prv;

            if (d==startpoint) {
                startpoint = nid;
            }
            if (d == endpoint) {
                endpoint = pid;
            }

            if (pid && nid){
                interval tmp;
                tmp.distance = umap[nid].x - umap[pid].x;
                tmp.left = umap[pid].x;
                tmp.right = umap[nid].x;
                tmp.left_id = pid;
                tmp.right_id = nid;

                pq.push(tmp);
            }

        }

        else if (op == 400){

            //마을 전체를 밝히기 위한 최소 소비 전력 r 
            while (!pq.empty()){
                interval tmp = pq.top(); 

                if (umap[tmp.left_id].status == true && umap[tmp.right_id].status == true) break;
                pq.pop();
            }

            int ans = max(2 * (umap[startpoint].x - 1), 2 * (n - umap[endpoint].x));
            ans = max(ans, pq.top().distance);
            cout << ans << "\n";
        }
        
    }
    

    return 0;
}