// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode* head)
{
    int res = 0;
    struct ListNode* c = head;
    while(c != NULL)
    {
        res++;
        c = c->next;
    }
    return res;
}

struct ListNode* middleNode(struct ListNode* head){
    int len = length(head);
    // printf("len: %d\n", len);
    struct ListNode* c = head;
    int count = 0;
    while(c != NULL) 
    {
        if(count == len/2)
        {
            return c;
        }
        count++;
        c = c->next;
    }
    return head;
}