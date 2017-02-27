#include <iostream>
#include <algorithm>

using std::max;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}