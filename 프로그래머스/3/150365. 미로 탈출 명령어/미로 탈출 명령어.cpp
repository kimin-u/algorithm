#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> nextgrid(pair<int, int> p, char dir){
    pair<int, int> ret;
    if (dir == 'd'){
        ret.first = p.first +1;
        ret.second = p.second;
    }    
    else if (dir == 'l'){
        ret.first = p.first;
        ret.second = p.second -1;
    }
    else if (dir == 'r'){
        ret.first = p.first;
        ret.second = p.second +1;
    }
    else if (dir == 'u'){
        ret.first = p.first-1;
        ret.second = p.second;
    }
    
    return ret;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int mindist = abs(r-x) + abs(c-y);
    if ((k-mindist)%2 != 0 || k < mindist) return "impossible";
    
    int cx, cy;
    cx = x;
    cy = y;
    int nx, ny;
    vector<char> vec = {'d','l','r','u'};
    for (int i=0; i<k; i++){
        for (auto &v: vec){
            pair<int, int> tmp  = nextgrid({cx,cy}, v);
            if (tmp.first < 1 || tmp.second < 1 || tmp.first > n || tmp.second > m) continue;
            nx = tmp.first;
            ny = tmp.second;
            
            int remain = k-i-1;
            int newdist = abs(r-nx) + abs(c-ny);
            
            if (newdist <= remain && (remain-newdist) % 2 == 0) {
                cx = nx;
                cy = ny;
                answer +=v;
                break;
            }
            
            
        }
    }
    
    
    return answer;
}