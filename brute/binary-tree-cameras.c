struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// https://www.cnblogs.com/grandyang/p/14131460.html
int minCameraCover(struct TreeNode* root){
    int res = 0;
    return (helper(root, &res)<1?1:0) + res;
}

int helper(struct TreeNode* node, int* res) {
    if(!node) return 2;
    int left = helper(node->left, res);
    int right = helper(node->right, res);
    if(left == 0 || right == 0) {
        *res += 1;
        return 1;
    }
    return (right == 1 || left == 1)?2:0;
}