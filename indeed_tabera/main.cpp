#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    s+="0";
    vector<string> vec;
    int start = 0;
    for(int i = 0, j = 1; j < s.size(); i++,j++)
    {
        if(s[i] == 'r' && s[j] == 'a')
        {

            vec.push_back(s.substr(start,i-start));
            start = j+1;
        }
        if(s[j] == '0')
        {
            vec.push_back(s.substr(start,j-start));
        }
    }

    string str = "";
    for(string ss : vec)
        str += ss;
    cout << str <<endl;

    return 0;
}