#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::stringstream;
using std::vector;
using std::string;


class Solution {
public:
    string simplifyPath(string path) {
        string res="", tmp = "";
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/'))
        {
            if(tmp == "" || tmp == ".") continue;
            if(tmp == "..")
                if(!stk.empty())
                    stk.pop_back();
            else if(tmp != "..") stk.push_back(tmp);
        }

        for(string s: stk) res+="/"+s;
        return res.empty() ? "/" : res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}