struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list = new ListNode{};
        ListNode* result = list;
        int sum;
        int carry = 0;
        while(l1 == nullptr || l2 == nullptr || carry > 0) {
            sum = 0;
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            list->next = new ListNode{sum%10};
            carry = sum/10;
            list = list->next;
        }
        return result->next;
    }
};

/**
 * Runtime: 55 ms, faster than 38.24% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 71.5 MB, less than 12.31% of C++ online submissions for Add Two Numbers.
 * 
 * @brief 
 * 
 * @return int 
 */
int main() {

}