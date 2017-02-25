#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        queue<TreeNode*> level;
        level.push(root);
        bool flag = false;

        while(!level.empty())
        {
            int size = level.size();
            vector<int> temp;
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* tempNode = level.front();
                if(tempNode->left != NULL)
                    level.push(tempNode->left);
                if(tempNode->right != NULL)
                    level.push(tempNode->right);
                temp.push_back(tempNode->val);
                level.pop();
            }
            if(flag) {reverse(temp.begin(),temp.end());}

            flag=!flag;
            ret.push_back(temp);
        }
        return ret;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);

    t1->left = t2;
    t1->right = t3;
    t3->right = t4;
    t3->left = t5;

    Solution mySolu;
    mySolu.zigzagLevelOrder(t1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}