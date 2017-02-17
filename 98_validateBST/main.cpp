#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        return helper(root,INT32_MIN,INT32_MAX);
//    }
//
//    bool helper(TreeNode* root, int min, int max)
//    {
//        if(root == NULL) return true;
//        if(root->val == min && root->left != NULL) return false;
//        if(root->val == max && root->right != NULL) return true;
//        if(root->val < min || root->val > max) return false;
//
//        return helper(root->right, root->val +1 , max) && helper(root->left, min, root->val -1);
//    }
//};

class Solution{
public:
    bool isFirst = true;
    bool isValidBST(TreeNode* root)
    {
        if(root == NULL) return true;
        int prev = 0;
        return isValidBST(root->left) &&
                check(root->val,prev) &&
                isValidBST(root->right);
    }

    bool check(int val, int& prev)
    {
        if(isFirst)
        {
            isFirst = false;
            prev = val;
        }

        if(prev >= val) return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}