#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int n,m;
unordered_map<string, string> umap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++){
        string site, pw;
        cin>>site>>pw;
        umap[site] = pw;
    }

    for (int i=0; i<m; i++){
        string site;
        cin>>site;
        cout<<umap[site]<<'\n';
    }
}