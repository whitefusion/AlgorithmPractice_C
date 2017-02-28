#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size() == 0 || inorder.size() ==0 ) return NULL;
        return helper(0,inorder.size()-1, 0,preorder, inorder );
    }

    TreeNode* helper(int inStart, int inEnd, int preStart,vector<int>& preorder, vector<int>& inorder)
    {
        if(inStart > inEnd || preStart > preorder.size() -1)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inMid = 0;
        for(int i = inStart; i <= inEnd; i++)
        {
            if(preorder[preStart] == inorder[i])
            {
                inMid = i;
                break;
            }
        }
        root->left = helper(inStart,inMid-1,preStart+1,preorder,inorder);
        root->right = helper(inMid+1,inEnd,preStart + inMid - inStart + 1,preorder,inorder);

        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}