#include <string>
#include <vector>

using namespace std;

int parse_time_to_seconds(const string& time_str) {
    size_t pos = time_str.find(':');
    int minutes = stoi(time_str.substr(0, pos));
    int seconds = stoi(time_str.substr(pos + 1));
    return minutes * 60 + seconds;
}

string seconds_to_time (int t){
    int minutes = t / 60;
    int seconds = t % 60;
    string mm = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
    string ss = (seconds < 10) ? "0" + to_string(seconds) : to_string(seconds);
    return mm + ':' + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int videolen = parse_time_to_seconds(video_len);
    int start =parse_time_to_seconds(op_start);
    int end = parse_time_to_seconds(op_end);
    int cur = parse_time_to_seconds(pos);
    for (auto command : commands){
        if (cur >= start && cur < end) cur = end;
        if (command == "prev"){
            cur -= 10;
            if (cur < 0 ) cur =0;
        }
        if (command == "next"){
            cur += 10;
            if (cur > videolen) cur = videolen;
        }
    }
    if (cur >= start && cur < end) cur = end;

    answer = seconds_to_time(cur);
    return answer;
}