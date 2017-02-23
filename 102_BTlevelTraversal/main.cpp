#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "TemplateArgumentsIssues"
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        queue <TreeNode*> myQ;
//        vector<vector<int>> result;
//        if(root == NULL) return result;
//        myQ.push(root);
//        TreeNode * temp = NULL;
//        while(!myQ.empty())
//        {
//            vector<int> level;
//            int size = myQ.size();
//            for(int i = 0; i < size ;i++)
//            {
//                temp = myQ.front();
//                if(temp->left != NULL)
//                    myQ.push(temp->left);
//                if(temp->right != NULL)
//                    myQ.push(temp->right);
//                level.push_back(temp->val);
//                myQ.pop();
//            }
//            result.push_back(level);
//        }
//        return result;
//    }
//#pragma clang diagnostic pop
//
//};
class Solution{
public :
    void helper(TreeNode* root, vector<vector<int>> & ret, int depth)
    {
        if(root == NULL) return;
        if(depth == ret.size())
        {
            vector<int> temp;
            ret.push_back(temp);
        }

        ret[depth].push_back(root->val);
        helper(root->left,ret,depth+1);
        helper(root->right,ret,depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        if(root == NULL) return ret;

        helper(root,ret,0);
        return ret;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}