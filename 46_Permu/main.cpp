#include <iostream>
#include <vector>

using namespace std;

/* A more elegant method */
/*vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;

    permuteRecursive(num, 0, result);
    return result;
}

// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
    if (begin >= num.size()) {
        // one permutation instance
        result.push_back(num);
        return;
    }

    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, result);
        // reset
        swap(num[begin], num[i]);
    }
}*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        helper(result,curr,nums);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &curr, const vector<int> nums) {
        if (curr.size() == nums.size()) {
            vector<int> temp(curr);
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(find(curr.begin(),curr.end(),nums[i]) != curr.end()) continue;
            curr.push_back(nums[i]);
            helper(result,curr,nums);
            curr.pop_back();
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}