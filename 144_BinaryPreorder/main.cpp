#include <iostream>
#include <vector>

using std::vector;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        helper(root,result);
        return result;
    }

    void helper(TreeNode *root, vector<int> &result)
    {
        if(root == NULL) return;

        result.push_back(root->val);
        helper(root->left,result);
        helper(root->right,result);

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}