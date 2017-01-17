#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target = - nums[i];
            int front = i + 1;
            int back = nums.size()-1;

            while(front < back){
                int sum = nums[front] + nums[back];

                if(sum < target)
                    front++;
                else if(sum > target)
                    back--;
                else{
                    vector<int> triplet(3,0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];

                    res.push_back(triplet);
                    // jump over duplicates of front
                    while(front < back && nums[front] == triplet[1]) front++;
                    // jump over duplicates of back
                    while(front < back && nums[back] == triplet[2]) back--;
                }
            }
            // jump over duplicates of target
            while(i + 1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}