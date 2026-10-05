#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

typedef long long ll;

using namespace std;

struct perfume{
    int id;
    int power;
    bool status;
};

int q;
int k;
int cnt = 1;

vector<int> blending_dp;
vector<ll> compose_dp;

unordered_map<int, perfume> umap;

void add_perfume(int v){
    perfume tmp;
    tmp.id = cnt;
    tmp.power = v;
    tmp.status = true;

    umap[tmp.id] = tmp;

    cnt++;
}

void remove_perfume(int idx){
    if (umap.find(idx) == umap.end()){
        cout<<"-1\n";
        return;
    }

    auto &tmp = umap[idx];
    if (tmp.status == false){
        cout<<"-1\n";
        return;
    }
    cout<<tmp.power<<'\n';
    tmp.status = false;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;

    int op;
    while (q--){
        cin>>op;
        if (op == 1){
            int n; cin>>n;
            for (int i=1; i<=n; i++){
                int s; cin>>s;
                add_perfume(s);
            }
        }

        else if (op == 2){
            int v; cin>>v;
            add_perfume(v);
        }

        else if (op == 3){
            int idx; cin>>idx;
            remove_perfume(idx);    
        }

        else if (op == 4){
            cin>>k;

            //blending_dp[i] = 향도의 합이 i가 되는 최소 개수를 의미. 

            //initialize;
            blending_dp.assign(3001, 1e9);
            for (auto &u :umap){
                if (u.second.status == false) continue;
                blending_dp[u.second.power] = 1;
            }

            for (int i=1; i<=k; i++){
                for (int j=1; j<i; j++){
                    blending_dp[i] = min (blending_dp[i], blending_dp[i-j] + blending_dp[j]);
                }
            }

            if (blending_dp[k] != 1e9){
                cout<<blending_dp[k]<<'\n';
            }
            else{
                cout<<"-1\n";
            }
            
        }

        else if (op == 5){
            cin>>k;

            //compose_dp[i] : 3가지 향료의 합이 i가 되는 경우의 수를 모두 count 
            //아래 코드는 3가지 향료의 합이 아닌 모든 경우를 고려한건가 ? 근데 경우의 수가 더 적게 출력됐는데 ?

            //initialize
            vector<ll> powercnt(3002, 0);
            for (auto &u : umap){
                if (u.second.status == false) continue;
                powercnt[u.second.power]++;
            }

            // 실제로 존재하는 향도 값만 모아둠 (최대 1100개)
            vector<int> vals;
            for (int p = 1; p <= 3000; p++)
                if (powercnt[p]) vals.push_back(p);

            // suf[p] = 향도가 p 이상인 향료 개수
            vector<ll> suf(3003, 0);
            for (int p = 3000; p >= 1; p--)
                suf[p] = suf[p+1] + powercnt[p];

            // pair_dp[s] = 탑+미들 합이 s인 경우의 수
            vector<ll> pair_dp(6001, 0);
            for (int a : vals)
                for (int b : vals)
                    pair_dp[a+b] += powercnt[a] * powercnt[b];

            // 베이스노트 향도가 (k - s) 이상이어야 함
            ll answer = 0;
            for (int s = 2; s <= 6000; s++){
                if (!pair_dp[s]) continue;
                int need = max(1, k - s);
                if (need <= 3000) answer += pair_dp[s] * suf[need];
            }
            cout<<answer<<'\n';
            
           
        }
    }
    return 0;
}