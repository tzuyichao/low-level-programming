#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    
    while(current) {
        if(current->val == val) {
            if(NULL == prev) {
                head = head->next; 
            } else {
                prev->next = current->next;
            }
        } else {
            prev = current;
        }
        current = current->next;
    }
    
    return head;
}