#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
bool compare(string a, string b){
    return a<b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    unordered_map<string, int> umap;

    for (int i =0 ; i<n; i++){
        string str; cin>>str;
        umap[str]++;
    }

    int maxv=0;
    for (auto u: umap){
        maxv=max(maxv, u.second);
    }
    vector<string> ans;
    for (auto u: umap){
        if (u.second == maxv){
            ans.push_back(u.first);
        }
    }

    sort(ans.begin(), ans.end(), compare);

    cout<<ans[0];


}