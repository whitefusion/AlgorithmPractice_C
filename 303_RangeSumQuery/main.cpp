#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> increSum;
public:
    NumArray(vector<int> &nums) {
        int tempSum = 0;
        for(auto n: nums){
            tempSum+=n;
            increSum.push_back(tempSum);
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? increSum[j] : increSum[j] - increSum[i - 1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0,2) << endl;
    cout << numArray.sumRange(2,5) << endl;
    cout << numArray.sumRange(0,5) << endl;
}