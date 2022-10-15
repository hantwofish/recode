#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;


class Solution2 {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int size_num = nums.size();
        vector<vector<int>> stor( size_num , vector<int>(2,0)   );
        for(int i = 0 ; i< size_num ; i++)
        {
            if(i== 0 )
            {
                stor[i][nums[i]]++;
                continue;
            }
            stor[i][ 0 ] +=  stor[i-1][ 0 ] ;
            stor[i][ 1]  +=  stor[i-1][ 1 ] ;
            stor[i][ nums[i] ] ++;
            
        }  

        
        for(int i =0 ; i< size_num ; i++)
        {
            cout << stor[i][0] << " " << stor[i][1] <<endl;
        }  
        
        return min( stor[size_num -1][0],stor[size_num -1][1] )*2 ;

        for(int i = size_num -1 ; i>= 0 ; i--)
        {
            if( stor[i][0] == stor[i][1]   )
                return stor[i][0]*2;
        }
        return 0;
    }
};

class Solution3 {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int size_lentn  = nums.size();
        stack<int> stk;
        int cord[2]={0,0}; // 记录栈中 0 和 1 的个数
        int resu = 0;
        for(int i = 0 ; i< size_lentn ; i++)
        {
           
            if(stk.empty())
            {
                stk.push(nums[i]);    
                cord[nums[i]]++;
            }
            else  if(!stk.empty() && cord[0] == cord[1])
            {
                while( !stk.empty() )
                {
                    
                    stk.pop();
                    resu++;
                }
                stk.push(nums[i]);    
                cord[nums[i]]++;
            }

            else if( !stk.empty() && cord[0] != cord[1] )
            {
                stk.push(nums[i]);
                cord[nums[i]]++;
            }

        cout << "i= " << i <<  " cor[0]= " << cord[0] << " cord[1]= " << cord[1] << " stk.size()= " << stk.size() << endl;
       

        }
        if(!stk.empty() && cord[0] == cord[1])
            resu += stk.size();

        
    return resu;

    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int size_lenth = nums.size(); 
        int countsum = 0; //记录前缀和
        map<int,int> record; // (前缀和 ， 下标) 前缀和为 0 比 1 多的个数，遇到 0 则 加一，遇到 1 则减一
        int max_lenth = 0;
        record[0] = -1;
        for(int i= 0 ; i < size_lenth ; i++)
        {
            if(nums[i] == 0)
                countsum += 1;
            else
                countsum += -1;
            if( record.find(countsum) != record.end() ) // 存在
            {
                max_lenth = max( max_lenth , i - record[countsum] );
            }
            else
                record[countsum] = i;
            cout << "i= " << i << "countsum = " << countsum <<endl;
        }
        return max_lenth;
    }
};


int main()
{
    Solution s1;
    vector<int> nums = {0,1,0};
    int resu = s1.findMaxLength(nums);
    cout << "resu= " <<resu << endl;

    return 0;

}