#include <iostream>

class Solution {
public:
    int reverse(int x) {
        long long reversed_n = 0;
        while(x){
            reversed_n = reversed_n * 10 + x%10;
            x/=10;
        }
        return (reversed_n < INT_MIN || reversed_n > INT_MAX) ? 0 : reversed_n;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}