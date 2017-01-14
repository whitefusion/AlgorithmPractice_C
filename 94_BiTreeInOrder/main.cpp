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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inHelper(root, result);
        return result;
    }

private:
    void inHelper(TreeNode* n, vector<int>& result){
        if(n == NULL) return;
        if(n->left != NULL) inHelper(n->left,result);
        result.push_back(n->val);
        if(n->right != NULL) inHelper(n->right,result);

    }
};

int main() {
    return 0;
}