#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int remain = k;
    
    for (int i=0; i<number.length(); i++){
        int pivot = number[i] - '0';
        
        int rightside=  number.length() - i;
        if (rightside == remain) {
            break;
        }
        
        bool flag = true;
        for (int j=i+1; j<i+1+remain; j++){
            int tmp = number[j] - '0';
            if (pivot >= tmp) continue;
            else {
                flag = false;
                break;
            }
        }
        
        if (!flag){
            remain--;
            continue;
        }
        else if (flag){
            answer += number[i];
        }
    }
    return answer;
}