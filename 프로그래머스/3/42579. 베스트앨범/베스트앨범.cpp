#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare_a(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
bool compare_b(pair<int, int>a, pair<int,int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> playpergenre;
    unordered_map<string, vector<pair<int, int>>> songs; // 장르, (재생횟수, 고유번호)
    for (int i=0; i<genres.size(); i++){
        playpergenre[genres[i]]+=plays[i];
        songs[genres[i]].push_back({plays[i], i});        
    }
    
    vector<pair<string, int>> vec_a; //장르, 재생횟수
    for (auto& u: playpergenre){
        vec_a.push_back({u.first, u.second});
    }
    sort(vec_a.begin(), vec_a.end(), compare_a);
    
    vector<pair<int, int>> vec_b; //재생횟수, 고유번호
    
    for (auto& a: vec_a){
        string cur_genre = a.first;
        for (auto &song : songs){
            if (song.first == cur_genre){
                vec_b = song.second;
            }
        }
        sort(vec_b.begin(), vec_b.end(), compare_b);
        
        for (int i=0; i < 2 && i < vec_b.size(); i++){
            answer.push_back(vec_b[i].second);
        }
    }
    
    
    
    return answer;
}