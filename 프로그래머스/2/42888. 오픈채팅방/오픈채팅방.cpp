#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<vector<string>> records;
    unordered_map<string, string> umap;
    stringstream ss;
    for (auto &r: record){
        ss.str(r);
        ss.clear();
        vector<string> tmpvec;
        string tmp;
        while(ss >> tmp){
            tmpvec.push_back(tmp);
        }
        records.push_back(tmpvec);
        
        if (tmpvec[0] == "Enter" || tmpvec[0] == "Change")
            umap[tmpvec[1]] = tmpvec[2];
    }
    
    for (auto& query : records){
        string name, tmp;
        if (query[0] == "Enter"){
            name = umap[query[1]];
            tmp = name + "님이 들어왔습니다.";
            answer.push_back(tmp);         
        }
        else if (query[0] == "Leave"){
            name = umap[query[1]];
            tmp = name + "님이 나갔습니다.";
            answer.push_back(tmp);       
        }
    }
    
    
    
    
    return answer;
}