#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    set<pair<long long, long long>> points;
    for (int i=0; i<line.size(); i++){
        for (int j=i+1; j<line.size(); j++){
            long long a = line[i][0];
            long long b = line[i][1];
            long long c = line[i][2];
            long long d = line[j][0];
            long long e = line[j][1];
            long long f = line[j][2];
            long long denominator = a*e - b*d;
            if (denominator == 0) continue;
            long long x_num = b*f - c*e;
            long long y_num = c*d - a*f;
            if (x_num % denominator == 0 && y_num % denominator == 0){
                long long x = x_num / denominator;
                long long y = y_num / denominator;
                points.insert({x, y});
            }
        }
    }
    vector<string> answer;
    if (points.empty()) return answer;
    
    long long min_x = points.begin()->first;
    long long max_x = points.begin()->first;
    long long min_y = points.begin()->second;
    long long max_y = points.begin()->second;
    
    for (auto& p : points) {
        if (p.first < min_x) min_x = p.first;
        if (p.first > max_x) max_x = p.first;
        if (p.second < min_y) min_y = p.second;
        if (p.second > max_y) max_y = p.second;
    }
    
    int width = (int)(max_x - min_x + 1);
    int height = (int)(max_y - min_y + 1);
    answer.assign(height, string(width, '.'));
    
    for (auto& p : points){
        int row = (int)(max_y - p.second);
        int col = (int)(p.first - min_x);
        answer[row][col] = '*';
    }
    return answer;
}
