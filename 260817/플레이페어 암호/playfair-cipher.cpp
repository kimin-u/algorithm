#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string str;
string key;

string makeKey(string key){
    string ret = "";

    vector<int> cnt_vec(26,0);
    for (auto &c: key){
        int idx = c-'A';
        if (cnt_vec[idx] == 0){
            cnt_vec[idx]++;
            ret += c;
        }
    }

    for (int i=0; i<26; i++){
        if (i == 9) continue;
        if (cnt_vec[i] != 0 ){
            continue;
        }
        else{
            ret += ('A' + i);
        }
    }
    // cout<<ret;

    return ret;
}

vector<string> seperateLetters(string str){
    vector<string> vec;
    for (int i=0; i<str.length();){
        //다음 인덱스 참조 --> seg fault 유의
        string tmp = "";
        char c1 = str[i];
        char c2;
        if (i+1 < str.length()){
            c2 = str[i+1];
        }
        else{
            c2 = 'X';
            tmp += c1;
            tmp += c2;
            vec.push_back(tmp);
            break;
        }

        int next_idx;
        if (c1 != c2){
            tmp += c1;
            tmp += c2;
            next_idx = i+2;
        }
        else{
            if (c1 == 'X'){
                tmp += c1;
                tmp += 'Q';
            }
            else{
                tmp += c1;
                tmp += 'X';
            }
            next_idx = i+1;
        }
        vec.push_back(tmp);
        i = next_idx;
    }

    // //debug
    // for (auto &v :vec){
    //     for (auto &c : v){
    //         cout<<c;
    //     }
    //     cout<< '\n';
    // }

    return vec;
}

pair<int, int> idx2grid(int idx){
    int i, j;
    i = idx/5;
    j = idx%5;

    return {i,j};
}

int grid2idx (pair<int, int> grid){
    int ret = grid.first *5 + grid.second;
    return ret;
}

int main() {
    // Please write your code here.
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>str;
    cin>>key;
    
    string tmp = makeKey(key);
    
    unordered_map<char, int> umap; //index-mapper.
    unordered_map<int, char> reverse_umap;
    for (int i =0; i<tmp.length(); i++){
        umap[tmp[i]] = i; //idx --> i,j : i=idx/5; j=idx%5;
        reverse_umap[i] = tmp[i];
    }

    //seperate by two letters
    vector<string> vec = seperateLetters(str);

    string answer = "";

    for (int i=0; i<vec.size(); i++){
        string tmpstr = vec[i];
        char c1 = tmpstr[0];
        char c2 = tmpstr[1];

        int idx1 = umap[c1];
        int idx2 = umap[c2];

        pair<int, int> grid1 = idx2grid(idx1);
        pair<int, int> grid2 = idx2grid(idx2);

        //같은 행인지 
        if (grid1.first == grid2.first){
            grid1.second = (grid1.second + 1)%5;
            grid2.second = (grid2.second + 1)%5;
        }

        else if (grid1.second == grid2.second){
            grid1.first = (grid1.first + 1) % 5;
            grid2.first = (grid2.first + 1 )% 5;
        }
        else{
            int tmp  = grid1.second;
            grid1.second = grid2.second;
            grid2.second = tmp;
        }

        idx1 = grid2idx(grid1);
        idx2 = grid2idx(grid2);

        c1 = reverse_umap[idx1];
        c2 = reverse_umap[idx2];

        answer+=c1;
        answer+=c2;       

   }   
    cout<<answer;

    return 0;
}
