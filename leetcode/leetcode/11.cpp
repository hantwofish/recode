#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size_len = height.size();
        vector<int>dp (size_len,0);
        for(int i = 1 ; i < size_len ; i++)
        {
            int cur_cir_amx = 0;
            for(int j = 0 ; j< i; j++)
            {
                cur_cir_amx = max( cur_cir_amx , min(height[i],height[j]) * abs(i-j) );
            }
            dp[i] = max( dp[i-1] ,cur_cir_amx );
            cout << "i= " << i << " " << dp[i] << endl;
        }
        return dp[size_len -1];
    }
};


int main()
{
    Solution s1;
    vector<int> height = {2,3,4,5,18,17,6};
    int resu = s1.maxArea(height);
    cout << "resu= " << resu << endl;


    return 0;
}

// 函数定义
int func_1(char *ptr)
{
    return 0;
}
int func_2(char * ptr)
{
    return 0;
}
// 定义函数指针


// 函数调用
int fuc(int (*pt_1)(char *ptr), int (*pt_2)(char *ptr), int nums){
    int resu = (*pt_1)(NULL) + (*pt_2)(NULL) + nums;
    return resu;
}

int main(){
    int (*pt_1)(char *ptr);
    int (*pt_2)(char *ptr);
    pt_1 = func_1;
    pt_2 = func_2;
    int resu = fuc(pt_1, pt_2, 3);
    cout << "resu= " << resu << endl;


}