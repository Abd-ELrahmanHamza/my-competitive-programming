/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        sort(nums.begin(), nums.end());
        ListNode *prevNode = nullptr, *curNode = head;
        while (curNode) {
            if (binary_search(nums.begin(), nums.end(), curNode->val)) {
                if (prevNode) {
                    prevNode->next = curNode->next;
                } else {
                    head = head->next;
                }
                curNode = curNode->next;
            } else {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
        return head;
    }
};
// @lc code=end
