#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.length();
    if (n==1) return 1;
    
    vector<string> vec;
    for (int i=1; i<=n/2; i++){
        //i개만큼의 단위로 묶음
        string tmpresult = "";
        
        for (int j= 0; j<s.length(); j++){
            string tmp = s.substr(j, i);
            int tmpcnt = 1;
            
            while (true){
                if (j + tmpcnt * i + i > (int)s.length()) break;
                string ttmp = s.substr(j+ tmpcnt* i, i);
                if (tmp == ttmp){
                    tmpcnt++;
                }
                else{
                    break;
                }
            }
            
            if (tmpcnt == 1){
                tmpresult += tmp;
                j += i-1;
            }
            else{
                tmpresult += to_string(tmpcnt);
                tmpresult += tmp;
                j += tmpcnt * i -1;
            }
        }
        vec.push_back(tmpresult);
    }
    
    vector<int> tmpvec;
    for (int i=0; i < vec.size(); i++){
        tmpvec.push_back(vec[i].size());
    }
    answer = *min_element(tmpvec.begin(), tmpvec.end());
    return answer;
}