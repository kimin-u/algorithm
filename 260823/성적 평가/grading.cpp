#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;
vector<vector<int>> scores;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){  return a.second < b.second;}
    return a.first > b.first;
}

int main() {
    cin.tie(nullptr);

    cin >> N;
    scores.resize(3, vector<int>(N));
    vector<int> sumvec(N, 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> scores[i][j];
        }
    }

    // Please write your code here.
    for (int j=0; j<N; j++){
        for (int i=0; i<3; i++){
            sumvec[j] += scores[i][j];
        }
    }

    vector<pair<int, int>> tmpvec(N,{0,0});
    for (int i=0; i<3; i++){
        vector<int> answer(N,0);
        for (int j=0; j<N; j++){
            tmpvec[j] = {scores[i][j], j};
        }
        sort(tmpvec.begin(), tmpvec.end(), compare);
        
        int currank = 1;
        for(int j=0; j<N; j++){
            if (j > 0 && tmpvec[j].first == tmpvec[j-1].first){

            }
            else{
                currank = j+1;
            }
            answer[tmpvec[j].second] = currank;
        }

        for (auto &a: answer){
            cout<<a<<" ";
        }
        cout<<'\n';
    }

    for (int j=0; j<N; j++){
        tmpvec[j] = {sumvec[j], j};
    }
    sort(tmpvec.begin(), tmpvec.end(), compare);

    vector<int> answer(N, 0);
    
    int currank = 1;
    for(int j=0; j<N; j++){
        if (j > 0 && tmpvec[j].first == tmpvec[j-1].first){

        }
        else{
            currank = j+1;
        }
        answer[tmpvec[j].second] = currank;
    }

    for (auto &a: answer){
            cout<<a<<" ";
        }
        cout<<'\n';

    

    return 0;
}
