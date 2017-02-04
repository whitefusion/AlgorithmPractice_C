#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tmp;
    vector<int> input;
    int nums = 0;
    while((cin>>tmp))
    {
        input.push_back(tmp);
        if(input.size() > 3 )
            nums = 3 + input[0]*input[1] + input[1]*input[2];
        if(input.size() == nums) break;
    }

    int n = input[0];
    int m = input[1];
    int k = input[2];

    vector<vector<int>> M_nm;
    vector<vector<int>> M_mk;

    int count = 3;
    for(int i = 0 ; i<n ;i++)
    {
        vector<int> temp;
        for(int j = 0; j < m ; j++)
        {
            temp.push_back(input[count]);
            count++;
        }
        M_nm.push_back(temp);
    }

    for(int i = 0; i < m; i++)
    {
        vector<int> temp;
        for(int j = 0; j < k; j++)
        {
            temp.push_back(input[count]);
            count++;
        }
        M_mk.push_back(temp);
    }

    int result[n][k];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int curr = 0;
            for(int p = 0; p < m ;p++)
            {
                curr += M_nm[i][p] * M_mk[p][j];
            }
            result[i][j] = curr;
        }
    }

    for(int i = 0 ;i < n;i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}