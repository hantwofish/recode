#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.empty())
            return 0;
        // 1. 根据 end 进行升序排序
        sort(points.begin(),points.end(),cmpl);
        // 2. 判断 重叠
        vector<int>cur = *(points.begin());
        for(int i = 1 ; i < points.size() ; i++)
        {
            if( points[i][0] <= cur[1]  )
                continue;
            else 
            {
                cur = points[i];
                result++ ; // 需要另外一支箭
            }
             
        }
        return result;
    }
    static bool cmpl(vector<int>&a , vector<int>&b)
    {
        return a[1] < b[1];
    } 
public:
    int result = 1;
};

int main()
{
    Solution s1;
    vector<vector<int>> points = { {2,3},{2,3} };
    int resu = s1.findMinArrowShots(points);
    cout << "main resu= " << resu << endl;

    return 0;
}

/*
{{10,16},{2,8},{1,6},{7,12}}

{{1,2},{3,4},{5,6},{7,8}}


{{1,2},{2,3},{3,4},{4,5}}

{{1,2}}

*/