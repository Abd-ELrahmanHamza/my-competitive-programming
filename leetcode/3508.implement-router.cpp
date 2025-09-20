/*
 * @lc app=leetcode id=3508 lang=cpp
 *
 * [3508] Implement Router
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Router {
public:
    struct Packet {
        int source, destination, timestamp;
        string key()
        {
            return to_string(source) + "-" + to_string(destination) + "-" + to_string(timestamp);
        }
    };
    unordered_map<string, bool> isExist;
    unordered_map<int, deque<int>> destTimestamp;
    deque<Packet> packetsSDQ;
    int memoryLimit;

    Router(int memoryLimit)
    {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {

        Packet p = { source, destination, timestamp };
        if (isExist[p.key()]) {
            return false;
        }
        packetsSDQ.push_back(p);
        destTimestamp[p.destination].push_back(p.timestamp);
        isExist[p.key()] = true;
        if (packetsSDQ.size() > memoryLimit) {
            isExist[packetsSDQ.front().key()] = false;
            destTimestamp[packetsSDQ.front().destination].pop_front();
            packetsSDQ.pop_front();
        }
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetsSDQ.empty()) {
            return {};
        }
        Packet p = packetsSDQ.front();
        packetsSDQ.pop_front();
        isExist[p.key()] = false;
        destTimestamp[p.destination].pop_front();
        return { p.source, p.destination, p.timestamp };
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto lower = lower_bound(destTimestamp[destination].begin(), destTimestamp[destination].end(), startTime);
        auto upper = upper_bound(destTimestamp[destination].begin(), destTimestamp[destination].end(), endTime);

        return upper - lower;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
// @lc code=end
