#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128] = {};
        int maxLen = 0;
        int start = 0;
        for(int i = 1; i <= s.size(); i++){
            if(alpha[s[i-1]-' '] > 0) {
                start = max(start,alpha[s[i-1]-' ']);
            }
            alpha[s[i-1] - ' '] = i;
            maxLen = max(maxLen,i-start);
        }
        return maxLen;
    }
};

int main() {
    Solution mySolution;
    cout << mySolution.lengthOfLongestSubstring("c") << endl;
    cout << mySolution.lengthOfLongestSubstring("dvdf") << endl;

    cout << mySolution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << mySolution.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzA") << endl;
    return 0;
}