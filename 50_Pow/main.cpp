#include <iostream>
using namespace std;

// cannot use normal recursive method due to the stack overflow.
// need to lower half power to save the stack
// be careful about the negative power

class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        double v = myPow(x,n/2);
        if(n%2) return n < 0 ? (1/x)*v*v : x*v*v;
        else return v*v;

    }
};

int main() {
    Solution mysolu;
    cout << mysolu.myPow(2,0) << "\n" << mysolu.myPow(2,3) << "\n" << mysolu.myPow(2,-2);
    return 0;
}