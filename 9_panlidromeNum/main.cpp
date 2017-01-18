#include <iostream>
//class Solution {
//public:
//    bool isPalindrome(int x) {
//        long revX = 0;
//        int tempX = x;
//        while(tempX){
//            revX = revX*10 + tempX % 10;
//            tempX /= 10;
//            if(revX > INT_MAX || revX < INT_MIN)
//                return false;
//        }
//        return revX == x < 0 ? -x : x;
//    }
//};


/* attention 0, 232 and negative number */
// only half digits are reversed in order not to use extra memory.
class Solution {
public:
    bool isPalindrome(int x) {
        long revX = 0;
        if(x % 10 == 0 && x != 0) return false;
        while(x > revX){
            revX = revX*10 + x % 10;
            x /= 10;
            if(x == 0) return true;
            if(revX > INT_MAX || revX < INT_MIN)
                return false;
        }
        return  x < 0 ? false : (x == revX) || (x == revX/10);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution mySolu;
    std:: cout << mySolu.isPalindrome(1);
    return 0;
}