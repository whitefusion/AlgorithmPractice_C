#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> strStack;
        map<char,char> pMap;
        pMap['('] = ')';
        pMap['['] = ']';
        pMap['{'] = '}';
        for(char a:s){
            if(a == '(' || a == '{' || a == '['){
                strStack.push(a);
            } else if( a == ')' || a == '}' || a == ']'){
                if(strStack.empty() || pMap[strStack.top()] != a) return false;
                else strStack.pop();
            }
        }
        return strStack.empty();

    }
};

int main() {
    string s = "()[]{}";
    Solution mySolu;
    cout << mySolu.isValid(s);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}