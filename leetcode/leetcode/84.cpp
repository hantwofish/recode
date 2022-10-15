#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea2(vector<int>& heights) 
    {

        int size_lenth = heights.size();
        if(size_lenth == 0) return 0;
        int result = 0;
        for(int i = 0 ; i< size_lenth ; i++)
        {
           // result = heights[i] ;
            // 向左延伸
            int left = i - 1;
            while( left >=0 && heights[left] >= heights[i])
            {
                left--;
            }

            // 向右延伸
            int right = i +1;
            while( right < size_lenth && heights[right] >= heights[i] )
            {
                right++;
            }
            result = max(result,heights[i] *( right - left -1 ));
            cout << "i= " << i << " resu= " << result <<endl;
        }
        return result;

    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {

    }
};

int main()
{
    Solution S1;
    vector<int> heights ={2,1,5,6,2,3};
    int re = S1.largestRectangleArea(heights);
    return 0;
}