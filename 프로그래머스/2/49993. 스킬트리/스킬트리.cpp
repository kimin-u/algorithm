#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto &skilltree: skill_trees){
        string str="";
        
        for (auto &c: skilltree){
            if (find(skill.begin(), skill.end(), c) != skill.end()){
                str+=c;
            }
        }
        
        if (str == skill.substr(0,str.length())){
            answer++;
        }
    }
    
    
    return answer;
}