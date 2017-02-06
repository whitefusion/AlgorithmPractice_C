#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n == 0 || k == 0) return result;
        vector<int> temp;
        helper(n,k,temp,result,1);
        return result;
    }

    void helper(int n, int k, vector<int> &curr, vector<vector<int>> &result, int start)
    {
        if(curr.size() == k)
        {
            vector<int> temp = curr;
            result.push_back(temp);
            return;
        }

        for(int i = start; i < n+1; i++)
        {
            curr.push_back(i);
            helper(n,k,curr,result,i+1);
            curr.pop_back();
        }
        return;
    }
};

int main() {
    Solution mySolu;
    vector<vector<int>> v = mySolu.combine(4,2);

    for(vector<int> vv: v){
        for(int vvv: vv)
            cout << vvv;
        cout << endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}