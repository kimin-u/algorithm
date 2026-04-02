#include <iostream>
#include <vector>

using namespace std;

int c, r;
int k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>c>>r;
    cin>>k;

    if (k > c * r) {
        cout<<0;
        return 0;
    }
    
    int cx=1, cy=1;
    int answer_x, answer_y;

    int cnt = 1;
    if (k == 1) {
        cout<<cx<<" "<<cy;
        return 0;
    }

    for (int i=0; i<r-1; i++){
        cy++;
        cnt++;
        if (cnt == k) {
            cout<<cx<<" "<<cy;
            return 0;
        }
    }


    int direction = 1;
    int step = 1;
    while (true){
        for (int j=0; j<c-step; j++){
            cx = cx + direction;
            cnt++;
            if (cnt == k) {
                cout<<cx<<" "<<cy;
                return 0;
            }
        }

        direction *= -1;
        for (int j=0; j<r-step; j++){
            cy = cy + direction;
            cnt++;
            if (cnt == k) {
                cout<<cx<<" "<<cy;
                return 0;
            }
        }
        
        step++;
    }
    
}