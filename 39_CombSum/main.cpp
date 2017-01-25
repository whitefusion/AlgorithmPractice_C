#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,result,temp,0);
        return result;
    }

    void helper(const vector<int> & candidates, int target,
                vector<vector<int>> &result, vector<int> &temp, int i)
    {
        if(target == 0)
        {
            vector<int> dummy(temp);
            result.push_back(dummy);
            return;
        }

        for(int k = i; k < candidates.size();k++)
        {
            if(target >= candidates[k])
            {
                temp.push_back(candidates[k]);
                helper(candidates, target - candidates[k], result, temp, k);
                temp.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {3,2,6,7};
    Solution mySolu;
    mySolu.combinationSum(nums,7);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}