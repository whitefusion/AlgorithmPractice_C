#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addPair(result,"",n,0);
        return result;
    }

    void addPair(vector<string>& result, string curr, int n, int m){
        if(n == 0 && m == 0){
            result.push_back(curr);
            return;
        }

        if(m > 0) addPair(result,curr+")",n,m-1);
        if(n > 0) addPair(result,curr+"(",n-1,m+1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}