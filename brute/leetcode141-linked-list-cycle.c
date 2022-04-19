#include <stdbool.h>
#include <stddef.h>

int VISITED = -10000000;

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) {
        return false;
    }
    if(head->val == VISITED) {
        return true;
    } else {
        head->val = VISITED;
        return hasCycle(head->next);
    }
}