#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        vector<int> temp;
        helper(nums,result,temp,0);
        return result;
    }

    void helper(const vector<int> nums,vector<vector<int>> &result, vector<int> &curr, int start)
    {
        if(start <= nums.size())
        {
            vector<int> temp;

            if(curr.empty())
                result.push_back(temp);
            else
            {
                temp = curr;
                result.push_back(temp);
            }

        }

        for(int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            helper(nums,result,curr,i+1);
            curr.pop_back();
        }
    }
};
int main() {
    Solution mySolu;
    vector<int> nums = {1,2,3};
    vector<vector<int>> v = mySolu.subsets(nums);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}