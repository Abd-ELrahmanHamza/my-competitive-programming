/*
 * @lc app=leetcode id=3408 lang=cpp
 *
 * [3408] Design Task Manager
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    struct P {
        int taskID, priority;
    };
    struct Compare {
        bool operator()(const P& a, const P& b)
        {
            if (a.priority != b.priority) {
                return a.priority < b.priority;
            }
            return a.taskID < b.taskID;
        }
    };
    priority_queue<P, vector<P>, Compare> tasksPQ;
    unordered_map<int, int> priorities;
    unordered_map<int, int> taskIDUserID;
    TaskManager(vector<vector<int>>& tasks)
    {
        for (auto task : tasks) {
            tasksPQ.push({ task[1], task[2] });
            priorities[task[1]] = task[2];
            taskIDUserID[task[1]] = task[0];
        }
    }

    void add(int userId, int taskId, int priority)
    {
        tasksPQ.push({ taskId, priority });
        priorities[taskId] = priority;
        taskIDUserID[taskId] = userId;
    }

    void edit(int taskId, int newPriority)
    {
        priorities[taskId] = newPriority;
        tasksPQ.push({ taskId, newPriority });
    }

    void rmv(int taskId)
    {
        priorities[taskId] = -1;
    }

    int execTop()
    {
        if (tasksPQ.empty())
            return -1;
        auto t = tasksPQ.top();
        while (t.priority != priorities[t.taskID]) {
            tasksPQ.pop();
            if (tasksPQ.empty())
                break;
            t = tasksPQ.top();
        }
        if (tasksPQ.empty())
            return -1;
        priorities[t.taskID] = -1;

        tasksPQ.pop();
        return taskIDUserID[t.taskID];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
// @lc code=end
