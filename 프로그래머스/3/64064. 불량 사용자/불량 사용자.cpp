#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> users;
vector<string> bans;
set<set<string>> results;

bool match(string user, string ban) {
    if (user.size() != ban.size()) return false;
    for (int i=0; i<ban.size(); i++) {
        if (ban[i] == '*') continue;
        if (ban[i] != user[i]) return false;
    }
    return true;
}

void dfs(int idx, set<string> selected) {
    if (idx == bans.size()) {
        results.insert(selected);  
        return;
    }
    for (auto& user : users) {
        if (selected.find(user) != selected.end()) continue; 
        if (match(user, bans[idx])) {
            auto next = selected;
            next.insert(user);
            dfs(idx+1, next);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    users = user_id;
    bans = banned_id;
    results.clear();

    dfs(0, {});

    return results.size();
}