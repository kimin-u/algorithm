#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size();
    int w = park[0].length();
    
    int i,j;
    for (int a=0; a< park.size(); a++){
        for (int b=0; b <park[a].size(); b++){
            if (park[a][b] == 'S'){
                i=a; j=b;
            }
        }
    }
    
    for (auto route : routes){
        char dir = route[0];
        int n = route[2]-'0';
        
        if(dir == 'N'){
            int tmp_i=i;
            while (n--){
                i--;
                if (i<0 || park[i][j] == 'X') {
                    i = tmp_i;
                    break;
                }
            }
        }
        else if (dir == 'S'){
            int tmp_i=i;
            while (n--){
                i++;
                if (i>=h || park[i][j] == 'X') {
                    i = tmp_i;
                    break;
                }
            }
        }
        else if (dir == 'W'){
            int tmp_j=j;
            while (n--){
                j--;
                if (j<0 || park[i][j] == 'X') {
                    j = tmp_j;
                    break;
                }
            }
        }
        else if (dir == 'E'){
            int tmp_j=j;
            while (n--){
                j++;
                if (j>=w || park[i][j] == 'X') {
                    j = tmp_j;
                    break;
                }
            }
        }
    }
    answer.push_back(i);
    answer.push_back(j);
    
    return answer;
}