#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pay attention to ""
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx = 0;; prefix+=strs[0][idx],idx++){
            for(int i = 0; i < strs.size();i++){
                if(idx >= strs[i].size() || (strs[0][idx] != strs[i][idx]))
                    return prefix;
            }
        }
        return prefix;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> strs(1,"a");
    Solution mySolu;
    cout << mySolu.longestCommonPrefix(strs);
    return 0;
}