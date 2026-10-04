#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ship{
    int id;
    int p;
    int r;
    int ready_time;
    int ver;
    bool status = true;
};

struct compare{
    bool operator() (ship a, ship b){
        if (a.p == b.p) return a.id > b.id;
        return a.p < b.p;
    }
};

int t, n;
priority_queue<ship, vector<ship>, compare> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waiting;
int vercnt = 0;
unordered_map<int, ship> umap;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;

    int op;
    for (int now = 0; now < t; now++){
        cin>>op;
        //op에 따른 분기
        while (!waiting.empty() && waiting.top().first <= now){
            int id = waiting.top().second;
            int rt = waiting.top().first;
            waiting.pop();

            auto it = umap.find(id);
            if (it == umap.end() || it -> second.status || it -> second.ready_time != rt) continue;

            it ->second.status = true;
            pq.push(it->second);
        }

        if (op == 100){
            cin>>n;
            for (int i=0; i<n; i++){
                ship tmp;
                cin>>tmp.id >> tmp.p>> tmp.r;
                tmp.ready_time = now;
                tmp.ver = ++vercnt;
                tmp.status = true;
                umap[tmp.id] = tmp;
                pq.push(tmp);
            }
        }

        else if (op == 200){
            ship tmp;
            cin>>tmp.id>>tmp.p>>tmp.r;
            tmp.ready_time = now;
            tmp.ver = ++vercnt;
            tmp.status = true;
            umap[tmp.id] = tmp;
            pq.push(tmp);
        }

        else if (op == 300){
            int id, pw;
            cin>>id>>pw;
            umap[id].p = pw;
            umap[id].ver = ++vercnt; 
            if (umap[id].status == true){
                pq.push(umap[id]);
            }
        }

        else if (op == 400){
            int sum = 0;
            int cnt = 0;
            vector<int> answer;

            while (cnt < 5 && !pq.empty()){
                ship s = pq.top();
                pq.pop();

                if (umap[s.id].ver != s.ver || umap[s.id].status == false) continue;

                sum += s.p;
                umap[s.id].status = false;
                umap[s.id].ready_time = now + umap[s.id].r;
                waiting.push({umap[s.id].ready_time, s.id});
                cnt++;
                answer.push_back(s.id);
            }

            cout<<sum<<" " << cnt<< " ";
            for (auto &a: answer){
                cout<<a<<" ";
            }
            cout<<'\n';
        }
        
    }
    return 0;
}