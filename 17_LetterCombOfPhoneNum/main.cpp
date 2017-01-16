#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for(int i = 0; i < digits.length();i++){
            vector<string> temp;
            for(int j = 0; j < dict[digits[i]-'0'].length();j++){
                if(result.size() == 0 && digits[i] >= '2'){
                    for(char c: dict[digits[i]-'0'])
                        temp.push_back(string(1,c));
                    break;
                }else {
                    for(int k = 0; k < result.size();k++){
                        temp.push_back(result[k]+string(1,dict[digits[i]-'0'][j]));
                    }
                }
            }
            result.swap(temp);
            temp.empty();
        }
        return result;
    }
};
int main() {
    Solution mySolu;
    vector<string> res1 = mySolu.letterCombinations("123");
    for(auto s: res1) cout << s << " ";
    return 0;
}