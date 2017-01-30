#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        if(intervals.empty()) return vector<Interval>{};
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start < b.start;});
        res.push_back(intervals[0]);
        for(int i = 0; i<intervals.size();i++)
        {
            Interval curr = intervals[i];
            if(curr.start <= res.back().end && curr.end > res.back().end) res.back().end = curr.end;
            else if(curr.start > res.back().end) res.push_back(curr);
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}