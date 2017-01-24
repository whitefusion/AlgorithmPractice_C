#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0] == val ? 0 : 1;
        int i = 0,j = 0;
        for(; i < nums.size();i++) {
            if(nums[i] == val) {
                j=i;
                while ( j < nums.size()-1 && nums[j] == val ) j++;
                if(j == nums.size()-1 && nums[j] == val) break;
                nums[i] = nums[j];
                nums[j] = val;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {4,5};
    Solution mySolu;
    cout << mySolu.removeElement(nums,5) << endl;
    for(int a: nums)
        cout << a << " " ;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}