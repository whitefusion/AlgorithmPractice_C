#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        char start = word[0];
        int m = board.size();
        int n = board[0].size();
        if(m*n < word.size()) return false;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0 ; j < board[i].size(); j++)
            {
                if(board[i][j] == start)
                {
                    if(helper(board,i,j,word,0)) return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, int i, int j, const string word, int k)
    {
        if(k == word.length()) return true;

        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return false;

        if(board[i][j] == word[k]) {
            char c = board[i][j];
            board[i][j] = '\0';

            if(helper(board,i+1,j,word,k+1) ||
               helper(board,i-1,j,word,k+1) ||
               helper(board,i,j+1,word,k+1) ||
               helper(board,i,j-1,word,k+1)) return true;

            board[i][j]  = c;

        }
        return false;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}