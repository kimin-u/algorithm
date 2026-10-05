#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

struct ant{
    int id;
    int x;
    bool status = true;
};

int q;
int cnt = 1;

unordered_map<int, ant> umap;

void add_ant(int x){
    ant tmp;
    tmp.id = cnt++;
    tmp.x = x;
    
    umap[tmp.x] = tmp;
}

void remove_ant(int q){
    for (auto &u : umap){
        if (u.second.id == q){
            umap.erase(u.second.x);
            break;
        }
    }
}


bool check(ll mid, int r, vector<int> &vec){
    int usedcnt = 0;
    
    int n = vec.size();
    int i=0;

    while (i < n){
        usedcnt++;
        if (usedcnt > r) return false;

        ll limit = (ll) vec[i] + mid;
        
        while (i < n && vec[i] <= limit) {
            i++;
        }    
    }

    return true;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;

    int op;
    while (q--){
        cin>>op;
        if (op == 100){
            int n; cin>>n;
            for (int i=0; i<n; i++){
                int x; cin>>x;
                add_ant(x);
            }

        }
        else if (op == 200){
            int p; cin>>p;
            add_ant(p);
        }
        else if (op == 300){
            int q; cin>>q;
            remove_ant(q);
        }
        else if (op == 400){
            int r; cin>>r;
            vector<int> vec;
            for (auto &u : umap){
                vec.push_back(u.first);
            }
            sort(vec.begin(), vec.end());

            //vec : 이제까지 건설된 개미집 오름차순 vector
            
            //최대 구간을 최소화 하는 문제.

            ll low = 0;
            ll high = 1000000000LL;

            while (low < high){
                ll mid = (low + high) /2;

                //r개의 개미로 mid시간안에 탐색이 가능한지? 
                if (check(mid, r, vec)) high = mid;
                else low = mid+1;
            }

            cout<<low<<'\n';
        }

    }

    return 0;
}