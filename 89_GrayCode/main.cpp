#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n)
    {
        if(n == 0)
        {
            vector<int> res;
            res.push_back(0);
            return res;
        }

        vector<int> res = grayCode(n-1);

        int originSize = res.size();
        int addN = 1 << (n-1);

        for(int i = originSize - 1 ; i >= 0; i--)
            res.push_back(addN+res[i]);

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}