#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a<b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int len = answers.size();
    
    vector<int> a,b,c;
    int val = 1;
    for (int i=0; i<len; i++){
        a.push_back(val++);
        if (val == 6) val = 1;
    }
    
    val = 1; 
    for (int i=0; i<len; i++){
        if (i%2==0){
            b.push_back(2);
        }
        else{
            b.push_back(val++);
            if (val == 2) val++;
            if (val == 6) val = 1;
        }
    }
    
    vector<int> tmp = {3,1,2,4,5};
    int idx = -1;
    for (int i=0; i<len; i++){
        if (i%2==0){
            idx++;
            if (idx ==5){
                idx = 0;
            }
        }
        c.push_back(tmp[idx]);
    }
    
    unordered_map<int, int> umap;    
    for (int i=0; i<len; i++){
        int tmp_ans = answers[i];
        if (a[i] == tmp_ans){
            umap[1]++;
        }
        if (b[i] == tmp_ans){
            umap[2]++;
        }
        if (c[i] == tmp_ans){
            umap[3]++;
        }
    }
    
    int tmp_max = -1e9;
    for (auto u : umap){
        if (u.second > tmp_max){
            tmp_max = u.second;
        }
    }
    
    for (auto u: umap){
        if (u.second == tmp_max){
            answer.push_back(u.first);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    return answer;
}