#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> answer;
int id_size;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    id_size = id_list.size();
    answer.assign(id_size, 0);
    
    
    unordered_map<string, int> mapper; //이름에 따른 index mapper
    int val=0;
    for (auto& id : id_list){
        mapper[id] = val++;
    }
    
    
    unordered_map<int, int> counter; //이름(idx)별 신고 당한 횟수 count
    unordered_map<int, vector<string>> ripot; // 이름 - 그 사람을 신고한 사람들
    stringstream ss;
    for (auto &r : report){
        ss.str(r);
        ss.clear();
        
        string tmp;
        vector<string> tmpvec;
        
        while (ss >> tmp){
            tmpvec.push_back(tmp);
        }
        
        //중복 제거; tmp[1]을 신고한 사람이 tmp[0]이 이미 있다면 안됨
        vector<string> &reporter = ripot[mapper[tmpvec[1]]];
        if (find(reporter.begin(), reporter.end(), tmpvec[0]) != reporter.end()){
            continue;
        }
        
        
        counter[mapper[tmpvec[1]]]++;
        reporter.push_back(tmpvec[0]);
        
    }
    
    for (int i=0; i<id_size; i++){
        if (counter[i] >= k){
            auto &reporter = ripot[i];
            for (int p=0; p<reporter.size(); p++){
                answer[mapper[reporter[p]]]++;
            }
        }
    }
    
    
    
    return answer;
}