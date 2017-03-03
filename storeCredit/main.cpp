#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findItem(int n, vector<int> myList)
{
    vector<int> result;
    unordered_map<int,int> myMap;

    for(int i = 0; i < myList.size();i++)
    {
        if(myMap.find(n - myList[i]) ==  myMap.end())
        {
            myMap[myList[i]] = i;
        }
        else
        {
            result.push_back(myMap[n - myList[i]]+1);
            result.push_back(i+1);
            return result;
        }
    }
    return result;
}

int main() {

    freopen("A-large-practice_in.txt","r",stdin);
    freopen("ans_large_out.txt","w",stdout);
    int t, n, m;

    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;  // read n and then m.
        vector<int> myList;
        for(int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            myList.push_back(k);
        }
        vector<int> result = findItem(n,myList);
        cout << "Case #" << i << ": " << result[0] << " " << result[1] << endl;
        // cout knows that n + m and n * m are ints, and prints them accordingly.
        // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}