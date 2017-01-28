#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = 0;
        int temp = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            temp = temp+nums[i] > nums[i] ? temp+nums[i] : nums[i];
            result = result > temp ? result : temp;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}