#include <iostream>
#include <vector>

using namespace std;
int cnt =0;
void dfs(int node, vector<vector<int>>& net, vector<bool>& visited){
    visited[node] = true;

    for(int i=0; i<net.size(); i++){
        if (net[node][i] == 1 && visited[i] == false){
            cnt++;
            dfs(i, net, visited);
        }
    }

}

int main(void)
{
    int cpu; //컴퓨터의 수 
    cin >> cpu;
    int n; // network의 엣지 수 ; 
    cin >> n;


    vector<vector<int>> net(cpu, vector<int>(cpu, 0));
    for(int i=0; i<net.size(); i++){
        net[i][i]=1;
    }
    vector<bool> visited(cpu, false);
    int tmp1, tmp2;
    for(int i=0; i<n; i++){
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        net[tmp1][tmp2] = 1;
        net[tmp2][tmp1] = 1;

    }

    dfs(0, net, visited);
    cout << cnt;
    

    return 0;
}