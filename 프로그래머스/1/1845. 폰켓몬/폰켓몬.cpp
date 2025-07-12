#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    int n = nums.size();
    for (int i=0; i<n; i++){
        s.insert(nums[i]);
    }
    int set_size = s.size();
    answer = set_size >= n/2 ? n/2 : set_size;
    return answer;
}