#include <iostream>
#include <vector>

using namespace std;

// My own solution
/*class NumArray {
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
};*/

// A faster solution.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        increSum.push_back(0);
        for(auto n: nums)
            increSum.push_back(increSum.back()+n);

    }

    int sumRange(int i, int j) {
        return increSum[j+1] - increSum[i];
    }
private:
    vector<int> increSum;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0,2) << endl;
    cout << numArray.sumRange(2,5) << endl;
    cout << numArray.sumRange(0,5) << endl;
}