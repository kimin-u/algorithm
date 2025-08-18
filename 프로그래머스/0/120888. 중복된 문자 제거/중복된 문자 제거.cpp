#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_map<char, int> umap;
    for (auto c: my_string){
        if (umap[c]==0) {
            umap[c]++;
            answer+=c;
        }
        else continue;
    }
    return answer;
}