#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> vec;
    
    int prevleft = 0;
    
    for (int i = 0; i<stations.size(); i++){
        int center = stations[i];
        int left = center - w;
        int right = center + w;
        
        vec.push_back(left-prevleft-1);
        prevleft = right;
    }
    // cout<<prevleft<<'\n';
    
    
    if (prevleft < n){
        vec.push_back(n-prevleft);
    }
    // for (auto &v: vec){
    //     cout<<v<<" ";
    // }
    
    int cover = 2*w+1;
    for (auto &v: vec){
        if (v <= 0) continue;
        
        int flag = v%cover;
        if (flag){
            answer += v/cover;
            answer++;
        }
        else{
            answer += v/cover;
        }
    }


    return answer;
}