#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] > b[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    //처리 가능한 mineral 개수
    int picksum = 0;
    for (const auto &pick : picks){
        picksum += pick;
    }
    picksum *=5;
    
    //5개씩 묶는다.
    int n = minerals.size();
    
    vector<vector<int>> vec;
    
    vector<int> tmp(3,0);
    
    int totalcnt = 0;
    int cnt =0;
    for (int i=0; i<n; i++){
        if (cnt==5){
            vec.push_back(tmp);
            cnt =0;
            tmp.assign(3,0);
        }
        
        if (minerals[i] == "diamond"){
            tmp[0]++;
        } else if (minerals[i] == "iron"){
            tmp[1]++;
        } else if (minerals[i] == "stone"){
            tmp[2]++;
        }
        
        cnt++;
        totalcnt++;
        
        // if (totalcnt > picksum) {
        //     break;
        // }
    }
    
    if (totalcnt <= picksum){
        vec.push_back(tmp);
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    int idx = 0;
    for (int i=0; i<picks.size(); i++){
        int num = picks[i];
        
        while (num >= 1 && idx < vec.size() ){
            vector<int> tmp = vec[idx];
            
            int tmpsum = 0;
            if (i == 0){
                tmpsum = tmp[0] + tmp[1] + tmp[2];
            } else if (i==1){
                tmpsum = tmp[0] *5;
                tmpsum += (tmp[1] + tmp[2]);
            } else if (i==2){
                tmpsum = tmp[0] * 25;
                tmpsum += (tmp[1] *5);
                tmpsum += tmp[2];
            }
            
            answer += tmpsum;
            idx++;
            num--;
        }
    }
    
    return answer;
}