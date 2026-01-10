#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int k, l;
bool compare(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>k>>l;

    vector<pair<string,int>> answer;
    unordered_map<string, int> umap;
    for(int i=0; i<l; i++){
        string str; cin>>str;
        umap[str] = i;
    }

    for (auto u : umap){
        answer.push_back({u.first, u.second});
    }

    sort(answer.begin(), answer.end(), compare);

    int lim = min((int)answer.size(), k);
    for (int i =0; i<lim; i++){
        cout<<answer[i].first<<'\n';
    }

    
}