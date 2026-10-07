#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct item{
    int id;
    int revenue;
    int dest;
    int cost;
    int value;
    bool status = true;
};

struct compare{
    bool operator() (item a, item b){
        if (a.value == b.value) return a.id > b.id;
        return a.value < b.value;
    }
};

struct compare2 {
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};

int q;
int n, m;
int s = 0;

vector<vector<pair<int, int>>> graph;  // 시작점 idx 기준으로 {도착 가능한 곳, 거리} vector.
unordered_map<int, item> umap; 
priority_queue<item, vector<item>, compare> pq;
vector<int> dist;

void dijkstra(){
    dist.assign(n, 1e9);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare2> dijk_pq;
    dijk_pq.push({dist[s], s});

    while (!dijk_pq.empty()){
        int cur = dijk_pq.top().second;
        int cost = dijk_pq.top().first;
        dijk_pq.pop();

        if (cost > dist[cur]) continue;

        //graph[cur]을 순회
        for (int i = 0; i<graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;

            if (dist[next] > dist[cur] + weight){
                dist[next] = dist[cur] + weight;
                dijk_pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;
    int op;

    while (q--){
        cin>>op;
        if (op == 100){
            cin>>n>>m;
            graph.assign(n, {});
            for (int i=0; i<m; i++){
                int v, u, w; cin>>v>>u>>w;
                graph[v].push_back({u,w});
                graph[u].push_back({v,w});
            }
            dijkstra();
        }
        else if (op == 200){
            int id, revenue, dest; cin>>id>>revenue>>dest;
            //시작점 s로부터 dest까지 이동하는 cost를 계산해야함 
            int cost = dist[dest];
            //구조체로 관리
            item tmp;
            tmp.id = id; tmp.revenue = revenue; tmp.dest = dest;
            tmp.cost = cost; tmp.value =revenue - cost; 
            umap[tmp.id] = tmp;
            //revenue - cost 큰 값을 기준으로 우선순위 큐를 만들어야함
            pq.push(tmp);
            //우선순위 큐에 들어가는 원소는 struct 타입.
            //우선순위 큐에 들어가는 원소는 동시에 umap에서도 관리되어야 함. 

        }
        else if (op == 300){
            int id; cin>>id;
            auto it = umap.find(id);
            if (it != umap.end()) it->second.status = false;
            
        }
        else if (op == 400){
            if (pq.empty()){
                cout<<-1<<'\n';
                continue;
            }
            int printflag = 0;
            while (!pq.empty()){
                item tmp = pq.top(); 
                if (umap[tmp.id].status == false) {
                    pq.pop(); continue;
                }
                if (umap[tmp.id].value < 0){
                    break;
                }
                pq.pop();
                cout<<tmp.id<<'\n';
                umap[tmp.id].status = false;
                printflag = 1;
                break;
                
            }
            
            if (!printflag){
                cout<<-1<<'\n';
            }
        }
        else if (op == 500){
            int tmps = s;
            cin>>s;
            dijkstra();
            while (!pq.empty()){
                pq.pop();
            }

            for (auto &u : umap){
                if (u.second.status == false) {
                    continue;
                }
                u.second.cost = dist[u.second.dest];
                u.second.value = u.second.revenue - u.second.cost;
                pq.push(u.second);
            }
        }
    }

    return 0;
}