#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vec.assign(101, vector<int>(101, 0));
    for (int i=0; i<4; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        for (int x=a; x<c; x++){
            for (int y=b; y<d; y++){
                vec[x][y] = 1;
            }
        }
    }

    int result = 0;
    for (int x=0; x<101; x++){
        for (int y=0; y<101; y++){
            if (vec[x][y] == 1){
                result++;
            }
        }
    }
    
    cout<<result;
}