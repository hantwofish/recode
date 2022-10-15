#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {

        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>>ans;
        bool flag = false ;// 目标是否被放入
        for(int i = 0 ; i < intervals.size(); i++)
        {
            // 1. 无交集
            if( intervals[i][0] > right || intervals[i][1] < left )
            {
                if( intervals[i][0] > right    ) // 插入值在左侧
                {
                    ans.push_back(  newInterval    );
                    ans.push_back( {intervals[i][0] , intervals[i][1] } );
                    flag = true;

                    if( flag )
                    {
                        i++ ;
                        while( i < intervals.size() )
                        {
                            ans.push_back(intervals[i]);
                            i++;
                        }
                        return ans;
                    }
 

                }
                else 
                {
                    ans.push_back( {intervals[i][0] , intervals[i][1] } );
                  //  ans.push_back(  newInterval    );
                    if( flag )
                    {
                        i++ ;
                        while( i < intervals.size() )
                        {
                            ans.push_back(intervals[i]);
                            i++;
                        }
                        return ans;
                    }
                }
                
            }
            else // 有重叠区间
            {
                // 取并集
                ans.push_back(  { min(intervals[i][0],left) , max( intervals[i][1] ,right )  }  );  
                flag = true;
                if( flag )
                {
                    i++ ;
                    while( i < intervals.size() )
                    {
                        ans.push_back(intervals[i]);
                        i++;
                    }
                    return ans;
                }
            }


        }

        return ans;
    }
};

int main()
{

    return 0;
}