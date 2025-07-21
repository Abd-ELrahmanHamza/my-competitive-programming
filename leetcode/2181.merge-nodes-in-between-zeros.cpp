/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};
class Solution
{
  public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *newHead = nullptr, *curPtr = nullptr;
        int curSum = 0;
        head = head->next;
        while (head)
        {
            while (head && head->val != 0)
            {
                curSum += head->val;
                head = head->next;
            }
            head = head->next;
            auto tempNode = new ListNode(curSum);
            curSum = 0;
            if (curPtr)
            {
                curPtr->next = tempNode;
                curPtr = tempNode;
            }
            else
            {
                curPtr = tempNode;
                newHead = curPtr;
            }
        }
        return newHead;
    }
};
// @lc code=end
