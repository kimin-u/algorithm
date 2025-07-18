#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> prime(1000001,1);
    for (int i=2; i<=n; i++){
        if (prime[i]==1){
            for (int j=2; j*i <=n; j++){
                prime[j*i] = 0;
            }
            answer++;
        }
    }
    return answer;
}