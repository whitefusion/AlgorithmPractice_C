#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left,root->right);
    }

    bool helper(TreeNode *right, TreeNode *left)
    {
        if((right == NULL && left != NULL) || (right != NULL && left == NULL)) return false;
        if(right == NULL && left == NULL) return true;
        if(right->val != left->val) return false;

        return helper(right->left,left->right) && helper(right->right,left->left);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}