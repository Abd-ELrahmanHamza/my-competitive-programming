#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> splitStringBySpace(string& s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events)
    {
        std::sort(events.begin(), events.end(), [](vector<string>& a, vector<string>& b) {
            if (stoi(a[1]) < stoi(b[1])) {
                return true;
            }
            if (stoi(a[1]) > stoi(b[1])) {
                return false;
            }
            if (a[0] == "OFFLINE")
                return true;
            if (b[0] == "OFFLINE")
                return false;
            return true;
        });
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            offline;
        vector<bool> isOffline(numberOfUsers);
        vector<int> numMessages(numberOfUsers);
        for (int i = 0; i < events.size(); i++) {
            auto curEvent = events[i];
            while (!offline.empty()) {
                auto t = offline.top();
                if (t.first <= stoi(curEvent[1])) {
                    offline.pop();
                    isOffline[t.second] = false;
                } else {
                    break;
                }
            }

            if (curEvent[0] == "OFFLINE") {
                offline.push({ stoi(curEvent[1]) + 60, stoi(curEvent[2]) });
                isOffline[stoi(curEvent[2])] = true;
            } else {
                if (curEvent[2] == "ALL") {
                    for (int& x : numMessages)
                        x++;
                } else if (curEvent[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (!isOffline[i]) {
                            numMessages[i]++;
                        }
                    }
                } else {
                    vector<string> ids = splitStringBySpace(curEvent[2]);
                    for (string& id : ids) {
                        int idI = stoi(id.substr(2));
                        numMessages[idI]++;
                    }
                }
            }
        }
        return numMessages;
    }
};