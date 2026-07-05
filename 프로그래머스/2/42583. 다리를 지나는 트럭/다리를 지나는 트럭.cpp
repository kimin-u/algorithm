#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<pair<int, int>> vec; // (무게, 머무른 시간)
    
    int idx = 0;
    while (true){
        answer++;
        int sum = 0;
        for (int i =0; i<vec.size(); i++){
            sum += vec[i].first;
            vec[i].second++;
            
            if (vec[i].second == bridge_length){
                sum -= vec[i].first;
                vec.erase(vec.begin() + i);
                i--;
            }
        }
        
        if (idx >= truck_weights.size() && vec.empty()){
            break;
        }

        if (sum + truck_weights[idx] <= weight && idx < truck_weights.size()){
            // 다리 위에 한개 올려야 함.
            //idx 를 올리고 idx 를 증가시켜얗
            vec.push_back({truck_weights[idx],0});
            idx++;
        }
        
    
    }
    
    return answer;
}