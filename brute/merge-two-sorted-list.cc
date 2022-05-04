

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void merge(ListNode* list1, ListNode* list2, ListNode* result) {
        if(list1 == nullptr && list2 == nullptr) {
            return;
        }
        if(list1 == nullptr) {
            result->next = list2;
            merge(nullptr, list2->next, list2);
        } else if(list2 == nullptr) {
            result->next = list1;
            merge(list1->next, nullptr, list1);
        } else {
            if(list1->val > list2->val) {
                result->next = list2;
                merge(list1, list2->next, list2);
            } else {
                result->next = list1;
                merge(list1->next, list2, list1);
            }
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        ListNode* result;

        if(list1->val > list2->val) {
            result = list2;
            merge(list1, list2->next, result);
        } else {
            result = list1;
            merge(list1->next, list2, result);
        }

        return result;
    }
};
 
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
// 
// Runtime: 13 ms, faster than 33.95% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 14.9 MB, less than 43.89% of C++ online submissions for Merge Two Sorted Lists.
int main() {

}