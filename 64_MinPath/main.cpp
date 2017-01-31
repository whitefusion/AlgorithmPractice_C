#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();

        int count[m][n];

        count[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
        {
            count[i][0] = 0;
            count[i][0] += (count[i-1][0] + grid[i][0]);
        }


        for(int j = 1; j < n; j++)
        {
            count[0][j] = 0;
            count[0][j] += (count[0][j-1] + grid[0][j]);

        }

        for(int i =1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                count[i][j] = (count[i-1][j] > count[i][j-1] ? count[i][j-1] : count[i-1][j]);
                count[i][j] += grid[i][j];
            }
        }

        return count[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid;
    grid.push_back({1,2});
    grid.push_back({1,1});
    Solution mySolution;
    std::cout << mySolution.minPathSum(grid) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}