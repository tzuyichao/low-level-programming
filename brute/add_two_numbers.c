/**
 * @file add_two_numbers.c
 * @author tzuyichao
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/
 * 
 * Runtime: 8 ms, faster than 97.18% of C online submissions for Add Two Numbers.
 * Memory Usage: 7.1 MB, less than 98.60% of C online submissions for Add Two Numbers.
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int len(struct ListNode *l) {
    struct ListNode* c = l;
    int counter = 0;
    while(c != NULL) {
        c = c->next;
        counter += 1;
    }
    return counter;
}

struct ListNode* carry(struct ListNode *l) {
    struct ListNode* c = l;
    int isCarry = 0;
    int c_val = 0;
    while(c != NULL) {
        if(isCarry) {
            c->val += c_val;
        }
        if(c->val >= 10) {
            isCarry = 1;
            c_val = c->val/10;
        } else {
            isCarry = 0;
            c_val = 0;
        }
        c->val = c->val % 10;
        if(c->next == NULL && isCarry) {
            struct ListNode* newNode;
            newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
            newNode->val = 0;
            newNode->next = NULL;
            c->next = newNode;
        }
        c = c->next;
    }
    return l;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    printf("l1 len: %d\n", len(l1));
    struct ListNode* r1 = l1;
    struct ListNode* r2 = l2;
    struct ListNode* c1 = r1;
    struct ListNode* c2 = r2;
    int len1 = len(r1);
    int len2 = len(r2);
    if(len1 >= len2) {
        while(c1 != NULL) {
            if(c2 != NULL) {
                c1->val += c2->val;
                c2 = c2->next;
            }
            c1 = c1->next;
        }
        return carry(r1);
    } else {
        while(c2 != NULL) {
            if(c1 != NULL) {
                c2->val += c1->val;
                c1 = c1->next;
            }
            c2 = c2->next;
        }
        return carry(r2);
    }
}

int main() {
    printf("Done.\n");
    return 0;
}