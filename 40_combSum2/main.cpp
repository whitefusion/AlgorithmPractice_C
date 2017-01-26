#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(),candidates.end());
        helper(result,curr,candidates, target, 0);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &curr,
                const vector<int> candidates, int target, int start)
    {
        if(target == 0)
        {
            vector<int> temp(curr);
            result.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size();i++)
        {
            if(target >= candidates[i])
            {
                if(i>start && candidates[i] == candidates[i-1]) continue;
                curr.push_back(candidates[i]);
                helper(result,curr,candidates,target-candidates[i],i+1);
                curr.pop_back();
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}