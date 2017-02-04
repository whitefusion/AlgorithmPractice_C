#include <iostream>
#include <vector>

using namespace std;
/* ancient number */
/***
 *  Input is a series of number;
 *  They appear in an ancinet formula;
 *  There could only be * and + in formula;
 *  Have no idea about the order of number;
 *  given a number N, found closet operation result;
 *  The formula is evaluated from left to right, which means + could prior than *.
 *
***/
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

vector<vector<int>> permutation(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> curr;
    helper(result,curr,nums);
    return result;
}

void recur(const vector<int> v, const int target, int currRes,int& currMin, int start)
{
    if(start == v.size())
    {
        currMin = currMin < abs(target - currRes) ? currMin : abs(target-currRes);
        return;
    }

    recur(v,target,currRes+v[start],currMin,start+1);
    recur(v,target,currRes*v[start],currMin,start+1);
}

int main() {
    vector<int> nk;
    vector<int> nums;
    int n;
    while(cin >> n)
    {
        if(nk.size() < 2)
            nk.push_back(n);
        else
            nums.push_back(n);
        if(nums.size() == nk[0])
            break;
    }

    int target = nk[1];

    vector<int> temp;
    vector<vector<int>> permut_nums = permutation(nums);

    int result = INT16_MAX;

    for(vector<int> v : permut_nums)
        recur(v,target,v[0],result,1);

    cout << result <<endl;
    return result;
}