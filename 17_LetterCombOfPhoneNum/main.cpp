#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Solution {
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
};*/

class Solution {
private:
    vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits);
    void combination(string, string , int , vector<string>& );

};

vector<string> Solution::letterCombinations(string digits) {
    vector<string> result;
    combination("",digits,0,result);
    return result;
}

void Solution::combination(string prefix, string digits, int offset, vector<string>& result){
    if(offset == digits.length()){
        if(prefix != "") result.push_back(prefix);
        return;
    }
    if(digits[offset] == '0' || digits[offset] == '1') combination(prefix,digits,offset+1,result);
    for(char a: dict[digits[offset]-'0']){
        prefix += a;
        combination(prefix,digits,offset+1,result);
        prefix = prefix.substr(0,prefix.length()-1);
    }
}

int main() {
    Solution mySolu;
    vector<string> res1 = mySolu.letterCombinations("");
    for(auto s: res1) cout << s << " ";
    return 0;
}