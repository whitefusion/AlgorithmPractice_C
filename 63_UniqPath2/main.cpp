#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int count[m][n];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                count[i][j] = 0;

        for(int i = 0 ; i < m ; i++)
        {
            if(obstacleGrid[i][0] == 1) break;
            count[i][0] = 1;
        }

        for(int j = 0; j < n; j++)
        {
            if(obstacleGrid[0][j] == 1) break;
            count[0][j] = 1;
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1;j < n; j++)
            {
                if(obstacleGrid[i][j] == 1) continue;
                count[i][j] += count[i-1][j];
                count[i][j] += count[i][j-1];
            }
        }

        return count[m-1][n-1];

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}