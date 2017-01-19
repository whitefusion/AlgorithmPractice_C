#include <iostream>
#include <vector>
using namespace std;

// three-pointer method
// be careful about the limit of i
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int myTar;
        int dist = INT_MAX,ans = 0;
        for(int i = 0 ; i < nums.size()-2;i++) {
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                myTar = nums[i] + nums[left] + nums[right];
                if (abs(myTar - target) < dist) {
                    ans = myTar;
                    dist = abs(myTar - target);
                }
                if (myTar - target > 0 ) right--;
                else if(myTar - target < 0) left++;
                else return target;
            }
            if(nums[left] == nums[right] && nums[left] == nums[i]) break;
        }
        return ans;
    }
};

int main() {
    vector<int> myNum = {0,0,0};
    Solution mySolution;
    cout << mySolution.threeSumClosest(myNum,1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}