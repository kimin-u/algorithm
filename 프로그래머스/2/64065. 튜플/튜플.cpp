#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> vec;
    
    string tmp="";
    vector<int> tmpvec;
    for (int i=0; i<s.length(); i++){
        if (s[i] == '{') continue;
        if (isdigit(s[i])){
            tmp += s[i];
        }
        else if (s[i] == ','){
            if (tmp.length() != 0){
                tmpvec.push_back(stoi(tmp));
                tmp="";
            }
        }
        else if (s[i] == '}'){
            if (tmp.length() != 0){
                tmpvec.push_back(stoi(tmp));
                tmp="";
            }
            vec.push_back(tmpvec);
            tmpvec.clear();
        }
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for (int i=0; i<vec.size(); i++){
        auto &tmpvec = vec[i];
        
        for (int j=0; j<vec[i].size(); j++){
            int target = vec[i][j];
            if (find(answer.begin(), answer.end(), target) == answer.end()){
                answer.push_back(target);
            }
        }    
    }
    
    return answer;
}