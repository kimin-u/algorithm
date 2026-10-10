#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct rabbit{
    int id;
    int i = 0;
    int j = 0;
    int iplusj = 0;
    ll d;
    int curjumpcnt = 0;
    ll score = 0;
    bool status = false; //k번의 턴 중에 한번이라도 뽑혀봤냐?
};

struct compare{
    bool operator() (rabbit a, rabbit b){
        if (a.curjumpcnt == b.curjumpcnt){
            if (a.iplusj == b.iplusj){
                if (a.i == b.i){
                    if (a.j == b.j){
                        return a.id > b.id;
                    }
                    return a.j > b.j;
                }
                return a.i > b.i;
            }
            return a.iplusj > b.iplusj;
        }
        return a.curjumpcnt > b.curjumpcnt;
    }
};

struct compare2{
    bool operator() ( rabbit a,  rabbit b){
        if (a.iplusj == b.iplusj){
            if (a.i == b.i){
                if (a.j == b.j){
                    return a.id < b.id;
                }
                return a.j < b.j;
            }
            return a.i < b.i;
        }
        return a.iplusj < b.iplusj;
    }
};

int q;
int n, m;
int p;
int k;
ll s;
ll total = 0; // 모든 토끼에게 공통으로 더해진 점수
unordered_map<int, rabbit> umap;
priority_queue<rabbit, vector<rabbit>, compare> pq;
priority_queue<rabbit, vector<rabbit>, compare2> pq2;


vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1}; // 상 하 좌 우 


//debug
void print(){
    cout<<"이동후 rabbit 좌표 및 score\n";
    for (auto &u : umap){
        cout<<"ID : "<<u.second.id << " (cnt : "<<u.second.curjumpcnt<<") "<< " {"<<u.second.i<<", "<<u.second.j<<"} - " <<u.second.score<<'\n';
    }
}

// 한 축(행 또는 열) 위에서 벽에 튕기며 d칸 이동한 최종 위치를 O(1)로 계산
// dir: +1 (증가 방향) 또는 -1 (감소 방향)
int moveLine(int pos, int len, int dir, ll d){
    if (len == 1) return 0;
    int period = 2 * (len - 1);
    ll x = (dir == 1) ? pos : period - pos; // 펼친 직선 위의 위치
    x = (x + d) % period;
    if (x >= len) x = period - x;
    return (int)x;
}

void jump(){
    rabbit tmp = pq.top();
    
    pq.pop();

    ll d  = umap[tmp.id].d;
    umap[tmp.id].status = true;
    tmp.status = true;

    //상 하 좌 우 4방향으로 d 만큼 점프했을 때의 좌표 (pair<int, int>) 와 실제로 점프한 횟수 를 저장해야함
    vector<pair<pair<int, int>, ll>> vec;

    int ci = tmp.i;
    int cj = tmp.j;

    vec.push_back({{moveLine(ci, n, -1, d), cj}, d}); // 상
    vec.push_back({{moveLine(ci, n, +1, d), cj}, d}); // 하
    vec.push_back({{ci, moveLine(cj, m, -1, d)}, d}); // 좌
    vec.push_back({{ci, moveLine(cj, m, +1, d)}, d}); // 우
    
    int summax = -1e9;
    int maxi = -1;
    int maxj = -1;
    int maxidx = -1;
    for (int i=0; i<4; i++){
        int tmpsum = vec[i].first.first + vec[i].first.second;
        if (tmpsum > summax){
            summax = tmpsum;
            maxi = vec[i].first.first ; maxj = vec[i].first.second;
            maxidx = i;
        }
        else if (tmpsum == summax){
            if (maxi < vec[i].first.first){
                maxi = vec[i].first.first;
                maxj = vec[i].first.second;
                maxidx = i;
            }
            else if (maxi == vec[i].first.first && maxj < vec[i].first.second){
                maxi = vec[i].first.first;
                maxj = vec[i].first.second;
                maxidx = i;
            }
        }
    }

    //maxidx 으로 tmp 토끼 이동
    tmp.i = maxi;
    tmp.j = maxj;
    tmp.iplusj= tmp.i + tmp.j;
    
    //umap에 갱신
    umap[tmp.id].i = tmp.i;
    umap[tmp.id].j = tmp.j;
    umap[tmp.id].iplusj = tmp.iplusj;
    umap[tmp.id].curjumpcnt++;


    //tmp토끼 제외한 모든 토끼 tmpi +tmpj만큼 점수 획득
    //전체에 공통으로 더하고(total), 뽑힌 토끼는 같은 값을 빼서 제외 효과를 낸다
    ll gain = tmp.iplusj + 2;
    total += gain;
    umap[tmp.id].score -= gain;

    pq.push(umap[tmp.id]);

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
            cin>>p;
            for (int i=0; i<p; i++){
                rabbit tmp;
                cin>>tmp.id >>tmp.d;

                umap[tmp.id] = tmp;
                
                pq.push(tmp);
            }
        }
        else if (op == 200){
            cin>>k>>s;
            //k번의 턴 중 한번이라도 뽑혀봤냐에 대한 flag를 false로 맞추기
            for (auto &u : umap){
                u.second.status = false;
            }
            while (!pq2.empty()){
                pq2.pop();
            }

            //simulation
            for (int i=0; i<k; i++){
                //우선순위 높은 토끼 뽑아서 멀리 보내주기 1회. * k번.
                jump();
                // print();
            }

            //턴이 모두 끝난 직후 umap 돌면서 행번호 열번호 ,... 새로운 pq를 통해서 우선순위 높은 토끼 골라서 s더해주기 해야함 .
            for (auto &u :umap){
                if (u.second.status == false) continue;
                pq2.push(u.second);
            }

            rabbit tmp = pq2.top(); 
            umap[tmp.id].score += s;

            // cout<<"턴ㅇ이  모두 끝났음 ---\n";
            // print();

        }
        else if (op == 300){
            int id, l;
            cin>>id>>l;
            umap[id].d *= l;
        }
        else if (op == 400){
            ll maxvalue = -1e18;
            for (auto &u : umap){
                if (maxvalue < u.second.score){
                    maxvalue = u.second.score;
                }
            }

            cout<<maxvalue + total<<'\n';

        }
    }

    return 0;
}