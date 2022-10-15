#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{

public:
    int cal(string nums, int K )
    {
        int lenth = nums.size();
        vector<vector<int>>dp(lenth , vector<int>(K ,0)); // 截至到第 i 个字符，最多使用 j 次变换， 1  的长度
        // 初始化
        for(int i = 0 ; i < lenth ; i++){
            if( i == 0 && nums[0] == 1){
                dp[0] = vector<int>(K ,1);
            }else if( i==0 && nums[0] == 0 ){
                dp[0] = vector<int>(K ,1);
                dp[0][0] = 0;
            }



            if( nums[i] == 1){
                for(int j = 0 ; j < K ; j++){
                    dp[i][j] = dp[i-1][j] +1;
                }
                
            }else if(nums[i] == 0){
                for(int j = 0 ; j < K ; j++){
                    dp[i][j] = dp[i-1][j] + j;
                }
            }

        }
        return dp[lenth-1][K-1];
    }



};

int main()
{
    Solution s1;
    string str = "11100011110";
    int K = 2;
    int resu = s1.cal(str, K);
    cout << "resu= " << resu << endl;
    return 0;
}
