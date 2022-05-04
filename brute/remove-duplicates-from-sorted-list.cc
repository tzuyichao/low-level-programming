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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = prev->next;
        while(curr != nullptr) {
            if(prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// 
// Runtime: 17 ms, faster than 36.01% of C++ online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 11.7 MB, less than 36.86% of C++ online submissions for Remove Duplicates from Sorted List.