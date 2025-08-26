#include <string>
#include <vector>
#include <cctype>

using namespace std;

void lower(string& id){
    for (int i=0; i<id.length(); i++){
        if (isupper(id[i])){
            id[i] = tolower(id[i]);
        }
    }    
}

string bbb(string& id){
    string ret = "";
    for (auto c: id){
        if (c>='a' && c<='z') ret += c;
        else if (c>='0' && c<='9') ret +=c;
        else if (c=='-' || c=='_' || c=='.') ret += c;
    }
    return ret;
}

string dot (string& id){
    string ret  = "";
    bool flag = false;
    for (int i=0; i<id.size(); i++){
        if (id[i] != '.'){
            flag = false;
            ret += id[i];
        }
        if (flag) continue;
        if (id[i] == '.'){
            flag = true;
            ret += id[i];
        }
    }
    return ret;
}
string fir(string& id){
    if (id.empty()) return "";
    string ret = id;
    if (!ret.empty() && ret.front() == '.') ret.erase(ret.begin());
    if (!ret.empty() && ret.back() == '.') ret.pop_back();
    return ret;
}

string lon(string& id){
    if (id.length() >= 16) return id.substr(0,15);
    else return id;
}

string emp(string& id){
    if (id.empty()) return "a";
    else return id;
}
string sho(string& id){
    if (id.length() ==1) {
        id.push_back(id[0]);
        id.push_back(id[0]);
    }
    else if (id.length() ==2){
        id.push_back(id[1]);
    }
    return id;
}
string solution(string new_id) {
    string answer = new_id;
    lower(answer);
    answer = bbb(answer);
    answer = dot(answer);
    answer = fir(answer);
    answer = emp(answer);
    answer = lon(answer);
    answer = fir(answer);
    answer = sho(answer);
    
    return answer;
}