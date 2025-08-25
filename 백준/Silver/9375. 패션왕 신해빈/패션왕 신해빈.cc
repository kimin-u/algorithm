#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int t;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        unordered_map<string, int> umap;
        cin>>n;
        for (int i=0; i<n; i++){
            string a, b;
            cin>>a>>b;
            umap[b]++;
        }
        int answer =1;

        for (auto u: umap){
            answer *= (u.second + 1);
        }
        answer--;
        cout<<answer<<'\n';
    }
}