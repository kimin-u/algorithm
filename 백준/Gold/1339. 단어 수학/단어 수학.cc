#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> vec;
vector<int> value;
vector<int> weight;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vec.assign(n,"");
    value.assign(26,-1);
    weight.assign(26,0);

    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    for (auto str: vec){
        int place = 1;
        for (int i=str.size()-1; i>=0; i--){
            weight[str[i]-'A'] += place;
            place *= 10;
        }
    }

    vector<pair<int, int>> order;
    for (int i = 0; i < 26; i++){
        if (weight[i] > 0) order.push_back({weight[i], i});
    }

    sort(order.begin(), order.end(), greater<>());

    int num = 9;
    for (auto &p : order){
        value[p.second] = num--;
    }

    int answer = 0;
    for (auto str: vec){
        string tmp="";
        for (auto s: str){
            tmp += to_string(value[s-'A']);
        }
        answer += stoi(tmp);
    }
    cout<<answer;

}