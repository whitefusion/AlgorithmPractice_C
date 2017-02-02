#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        int counter[n+1];
        for(int i = 0; i<=n; i++)
            counter[i] = 0;
        counter[0] = 1;
        counter[1] = 1;

        for(int i = 2;i <= n;i++)
        {
            counter[i] += (counter[i-1]+counter[i-2]);
        }
        return counter[n];
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}