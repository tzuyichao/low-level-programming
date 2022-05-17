#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// 86. Partition List
// https://leetcode.com/problems/partition-list/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<int> s;
        queue<int> l;
        ListNode* c = head;
        while(c) {
            if(c->val >= x) {
                l.push(c->val);
            } else {
                s.push(c->val);
            }
            c = c->next;
        }
        
        c = head;
        while(c) {
            while(!s.empty()) {
                c->val = s.front();
                s.pop();
                c = c->next;
            }
            while(!l.empty()) {
                c->val = l.front();
                l.pop();
                c = c->next;
            }
        }
        
        return head;
    }
};