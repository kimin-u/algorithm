#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (int a, int b){
    string aa, bb;
    aa=to_string(a); bb= to_string(b);
    return aa + bb > bb + aa;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for (const auto& n : numbers){
        answer += to_string(n);
    }
    if (answer[0] == '0') return "0";
    return answer;
}