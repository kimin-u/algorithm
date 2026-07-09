#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;

string to_minute(string hour){
    int hh = stoi(hour.substr(0,2));
    int mm = stoi(hour.substr(3,2));
    
    string ret = "";
    int rethh = hh*60;
    rethh += mm;
    ret = to_string(rethh);
    return ret;
}

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    stringstream ss;
    
    vector<vector<string>> recoords;
    for (int i=0; i<records.size(); i++){
        auto &record = records[i];
        ss.str(record);
        ss.clear();
        string tmp;
        vector<string> ttmp;
        while(ss>>tmp){
            ttmp.push_back(tmp);
        }
        recoords.push_back(ttmp);
    }
    
    for (auto &record : recoords){
        record[0] = to_minute(record[0]);
    }
    

    unordered_map<string, string> umap; //차량 번호, 입차시간
    unordered_map<string, int> time_cum; //차량번호, 총 주차 시간 
    for (auto &record : recoords){
        if (record[2] == "IN"){
            umap[record[1]] = record[0];
        }
        else if (record[2] == "OUT"){
            int tmptime = stoi(record[0]) - stoi(umap[record[1]]);
            umap.erase(record[1]);
            time_cum[record[1]] += tmptime;
        }
    }
    
    for (auto &u : umap){
        time_cum[u.first] += (stoi(to_minute("23:59")) - stoi(u.second));
    }
    
    vector<pair<int,int>> vec; //차 번호, 주차 요금 
    for (auto &time : time_cum){
        vec.push_back({stoi(time.first), time.second});
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for (auto &v: vec){
        int total = fees[1]; // 기본 요금으로 시작
        
        if (v.second > fees[0]) {
            int extra_time = v.second - fees[0];
            total += ceil((double)extra_time / fees[2]) * fees[3];
        }
        
        answer.push_back(total);
    }
    return answer;
}