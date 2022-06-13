
struct ListNode {
    int val;
    struct ListNode *next;
};

int length(struct ListNode* head)
{
    int res = 0;
    struct ListNode* curr = head;
    while(curr != NULL) {
        res++;
        curr = curr->next;
    }
    return res;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    int len = length(head);
    if(len == 1 && n == 1) {
        return NULL;
    }
    int c = 1;
    while(curr != NULL) {
        if(c == len-n) {
            prev = curr;
        }
        if(c == len-n+1) {
            if(prev == NULL) {
                return curr->next;
            } else {
                prev->next = curr->next;
            }
        }
        c++;
        curr = curr->next;
    }
    return head;
}