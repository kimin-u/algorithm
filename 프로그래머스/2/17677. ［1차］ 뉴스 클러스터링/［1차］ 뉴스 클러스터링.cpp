#include <algorithm>
#include <string>
#include <cctype>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    for (int i=0; i<str1.length(); i++){
        str1[i] = tolower(str1[i]);
    }
    for (int i=0; i<str2.length(); i++){
        str2[i] = tolower(str2[i]);
    }
    
    vector<string> vec1, vec2;
    unordered_map<string,int> cnt1, cnt2;

    for (int i=0; i<str1.length()-1; i++){
        if (isalpha(str1[i]) && isalpha(str1[i+1])){
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i+1];
            cnt1[tmp]++;
        }
    }
    for (int i=0; i<str2.length()-1; i++){
        if (isalpha(str2[i]) && isalpha(str2[i+1])){
            string tmp = "";
            tmp += str2[i];
            tmp += str2[i+1];
            cnt2[tmp]++;
        }
    }

    
    //vec1과 vec2의 자카드 유사도를 구하면 됨, 
    //합집합
    
    unordered_map<string,int> merged = cnt1;
    for (auto &p : cnt2) {
        merged[p.first];
    }
    
    
    int inter_cnt = 0, sum_cnt = 0;
    for (auto &p : merged) {
        int c1 = cnt1.count(p.first) ? cnt1[p.first] : 0;
        int c2 = cnt2.count(p.first) ? cnt2[p.first] : 0;
        inter_cnt += min(c1, c2);
        sum_cnt += max(c1, c2);
    }

    if (sum_cnt == 0) return 65536;

    double tmpanswer = (double)inter_cnt / (double)sum_cnt;
    tmpanswer *= 65536;
    return (int)tmpanswer;
}