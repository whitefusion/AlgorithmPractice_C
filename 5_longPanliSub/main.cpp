#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longest;

    string longestPalindrome(string s) {
        longest = "";
        if(s.length() < 2) return s;
        for(int i = 0; i < s.length(); i++){
            // when palindrome is odd
            helper(s,i,0);
            // when palindrome is even
            helper(s,i,1);
        }
        return longest;
    }
private:
    void helper(string s, int idx, int offset){
        int left = idx;
        int right = idx + offset;
        while(left >=0 && right < s.length() && s[right] == s[left]){
            left--;
            right++;
        }
        string currLong = s.substr(left+1,right-1-left);
        if(currLong.length() > longest.length())
            longest = currLong;
    }
};
int main() {
    Solution mySolu;
    cout << mySolu.longestPalindrome("ab") << endl;
    cout << mySolu.longestPalindrome("bab") << endl;
    cout << mySolu.longestPalindrome("abbabad") << endl;
    cout << mySolu.longestPalindrome("cbba") << endl;

    return 0;
}