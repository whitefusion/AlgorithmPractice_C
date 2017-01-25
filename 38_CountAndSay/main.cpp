#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";

        string curr = countAndSay(n-1);

        string temp = "";
        int i = 0, k = 0;
        for(; i < curr.size();i++){
            if(curr[i] == curr[k]) continue;
            else {
                int count = i-k;
                temp+=(count+'0');
                temp+=curr[k];
                k = i;
            }
        }
        temp+=(i-k+'0');
        temp+=(curr[k]);
        return temp;
    }
};

int main() {
    Solution mySolu;
    for(int n = 0; n < 8; n++)
        cout << mySolu.countAndSay(n) << endl;
    return 0;
}