#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool compare(struct TreeNode* node1, struct TreeNode* node2) {
    if(NULL == node1 && NULL == node2) {
        return true;
    }
    if(NULL == node1 && NULL != node2) {
        return false;
    }
    if(NULL != node1 && NULL == node2) {
        return false;
    }
    if(node1->val != node2->val) {
        return false;
    } else {
        return compare(node1->left, node2->right) && compare(node1->right, node2->left);
    }
}

bool isSymmetric(struct TreeNode* root){
    if(NULL == root) {
        return true;
    }
    return compare(root->left, root->right);
}

void main() {
    printf("Result: %d\n", isSymmetric(NULL));
}