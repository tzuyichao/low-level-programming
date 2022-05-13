
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
class Solution {
private:
    int height(Node* root) {
        if(!root) return 0;
        return 1 + max(height(root->right), height(root->left));
    }   
public:
    Node* connect(Node* root) {
        //cout << height(root) << endl;
        if(!root) {
            return nullptr;
        }
        Node* p = root->next;
        while(p) {
            if(p->left) {
                p = p->left;
                break;
            }
            if(p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if(root->right) {
            root->right->next = p;
        }
        if(root->left) {
            root->left->next = root->right != nullptr?root->right:p;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};