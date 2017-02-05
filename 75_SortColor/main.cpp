#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        if(nums.size() == 0) return;

        for(int i = 0; i < nums.size();i++)
        {
            if(!nums[i]) continue;
            for(int p = i; p < nums.size(); p++)
            {
                if(nums[p] < nums[i])
                {
                    int temp = nums[p];
                    nums[p] = nums[i];
                    nums[i] = temp;
                }
                if(!nums[i]) continue;
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}