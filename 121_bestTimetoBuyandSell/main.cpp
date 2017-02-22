#include <iostream>
#include <vector>
#include
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int result = 0;
        int currMin = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(currMin < prices[i])
                currMin = prices[i];
            result = result > prices[i] - currMin ? result : prices[i] - currMin;
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}