#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_a (int a, int b){
    return a<b;
}
bool compare_b (int a, int b){
    return a>=b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    int len = A.size();
    
    sort(A.begin(), A.end(), compare_a);
    sort(B.begin(), B.end(), compare_b);
    
    for (int i=0; i<len; i++){
        answer += (A[i] * B[i]);
    }
    
    return answer;
}