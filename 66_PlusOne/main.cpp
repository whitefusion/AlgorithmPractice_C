#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int carry = 1;

        for(int i = digits.size()-1; i >= 0 && carry; i--)
        {
            if(digits[i] == 9 && carry)
            {
                digits[i] = 0;
                carry =1;
            }
            else
            {
                digits[i] += carry;
                carry = 0;
            }
        }

        if(carry)
        {
            digits.insert(digits.begin(),1);
        }

        return digits;
    }
};
int main() {
    vector<int> dig = {4,5,9};
    Solution mySolu;
    mySolu.plusOne(dig);
    for(auto a: dig)
        cout << a;
    return 0;
}