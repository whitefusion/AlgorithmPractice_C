#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> myResult;
        vector<int> temp = {};
        sort(nums.begin(),nums.end());
        helper(nums, myResult,temp,0);

        for(vector<int> v: myResult)
            result.push_back(v);
        return result;
    }

    void helper(const vector<int> nums, set<vector<int>> &result, vector<int> &temp, int start)
    {
        result.insert(temp);

        for(int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(nums,result,temp,i+1);
            temp.pop_back();
        }
    }
};*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp = {};
        sort(nums.begin(),nums.end());
        helper(nums, result,temp,0);

        return result;
    }

    void helper(const vector<int> nums, vector<vector<int>> &result, vector<int> &temp, int start)
    {
        result.push_back(temp);

        for(int i = start; i < nums.size(); i++)
        {
            if(i == start || nums[i] != nums[i-1])
            {
                temp.push_back(nums[i]);
                helper(nums,result,temp,i+1);
                temp.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {4,4,1,4};
    Solution mySolu;
    vector<vector<int>> res = mySolu.subsetsWithDup(nums);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}