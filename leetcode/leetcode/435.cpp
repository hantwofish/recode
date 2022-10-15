#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1. 根据结束的时间先后进行排序。
        sort(intervals.begin(),intervals.end(),cmp1);

        // 2. 与 结束最早的有交集的区间进行删除
        vector<int>cur = *intervals.begin();
        for(auto i = intervals.begin()+1 ; i != intervals.end();i++)
        {
            if((*i)[0] < cur[1]) // 有重叠
                result ++ ; // 需要移除，移除个数加加
            else  // 没有重叠
                cur = *i;
        }

        return result;
    }
    static bool cmp1( vector<int> &a,  vector<int> &b)
    {
        return a[1] < b[1];
    }
    void my_print(vector<vector<int>>& intervals)
    {
        for(int i = 0 ; i < intervals.size();i++)
        {
            for(int j =0 ; j < intervals[i].size(); j++)
            {
                cout << " " <<  intervals[i][j] << " " ;
            }
            cout << endl;
        }

    }
public:
    int result = 0;
};

int main()
{
    Solution s1;
    vector<vector<int>> intervals ={ {1,2} ,{2,3}};
    int resu = s1.eraseOverlapIntervals(intervals);
    cout << "resu= " << resu << endl;
    s1.my_print(intervals);
    return 0;
}