// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 100

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* db[MAX];
    
    struct ListNode* c = head;
    int count = 0;
    while(c != NULL) 
    {
        db[count] = c;
        count++;
        c = c->next;
    }
    return db[count/2];
}