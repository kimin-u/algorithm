#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

struct jewel{
    int id;
    int weight;
    int value;
    bool status = true;
};

int q;
int cnt = 1;

unordered_map<int, jewel> umap;

void add_jewel(int w, int v){
    jewel tmp;
    tmp.id = cnt;
    tmp.weight =w;
    tmp.value = v;

    umap[tmp.id] = tmp;
    cnt++;
}

void remove_jewel(int idx){
    if (umap.find(idx) == umap.end()){
        cout<<"-1\n";
        return;
    }

    auto &tmp = umap[idx];
    if (tmp.status == false){
        cout<<"-1\n";
        return;
    }

    cout<<tmp.value<<'\n';
    tmp.status = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;

    int op;
    while (q--){
        cin>>op;

        if (op==1){
            int n; cin>>n;
            for (int i=1; i<=n; i++){
                int w, v; cin>>w>>v;
                add_jewel(w,v);
            }

        }
        else if (op==2){
            int w, v; cin>>w>>v;
            add_jewel(w,v);
        }
        else if (op==3){
            int idx; cin>>idx;
            remove_jewel(idx);
        }
        else if (op==4){
            int w; cin>>w;
            
            //무게 합 w 이하 중에 가장 큰 보석의 가치의 합을 출력해야함
            //dp[i] : 무게 합이 i 이하 중에 가치의 합 최댓값을 저장
            vector<ll> dp(3001,0);
            for (auto &u: umap){
                if (u.second.status == false) continue;
                
                int wt = u.second.weight;
                ll val = (ll)u.second.value;

                for (int i=w; i>=wt; i--){
                    dp[i] = max(dp[i], dp[i-wt] + val);
                }
            }

            
            cout<<dp[w]<<'\n';
            
        }
        else if (op==5){
            int d; cin>>d; //0 이상 3000이하

            //번호가 다른 서로 다른 두 보석을 고른다.
            //두 보석의 무게 차이가 d 이하인 쌍의 개수?
            vector<ll> valid(3001, 0);
            int earlystop = 0;
            for (auto &u : umap){
                if (u.second.status == false) continue;
                valid[u.second.weight]++;
                earlystop++;
            }

            if (earlystop < 2){
                cout<<"0\n";
                continue;
            }

            //valid : 해당 무게의 보석이 몇개 있는지 .
            //pre[x] : 무게 x 이하의 보석의 개수 counting (누적합)

            vector<ll> pre(3001, 0);
            for (int i=1; i<3001; i++){
                pre[i] = pre[i-1] + valid[i];
            }

            ll answer = 0;

            for (int i=1; i<3001; i++){
                if (valid[i] == 0) continue;

                int high = min(3000, i+d);

                answer += (valid[i] * (valid[i]-1)/2);

                answer += (valid[i] * (pre[high]- pre[i]));
            }

            cout<<answer<<'\n';


        
        }
        
    }

    return 0;
}