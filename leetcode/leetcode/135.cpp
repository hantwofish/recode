#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int candy(vector<int>& ratings) {
        // 找出最小值
        vector<int>data(ratings.begin(),ratings.end());
        sort(data.begin(),data.end());
        int min_data = data[0];

        int resu = INT32_MAX;
       
        cout << "min_data= " << min_data << endl;
        for(int i = 0 ; i < ratings.size(); i++){
            if(ratings[i] == min_data){
                resu = min(resu,one_case(ratings, i));
            }
        }
    
        return resu;
        
 
    }

    int one_case(vector<int>& ratings,int index)
    {
        vector<int>resu(ratings.size(),0);
        resu[index] = 1;
        // 最小位置向左
        for(int i = index -1 ; i>= 0 ; i--){
            if(ratings[i] <= ratings[i+1]){
                resu[i] = resu[i+1] -1 > 0 ? resu[i+1] -1 : 1;
            }else {
                resu[i] = resu[i+1] + 1; 
            }
        }
        // 最小位置向右
        for(int i = index +1 ; i<  ratings.size() ; i++){
            if(ratings[i] <= ratings[i-1]){
                resu[i] = resu[i-1] -1 > 0 ? resu[i-1] -1 : 1;
            }else {
                resu[i] = resu[i-1] + 1; 
            }
        }
        my_print(resu);



        // 检查
        // 左规则
        for(int i= 1 ; i < ratings.size() ; i++){
            if(ratings[i] > ratings[i-1] && resu[i] > resu[i-1]){
                continue;
            }else if(ratings[i] < ratings[i-1] && resu[i] < resu[i-1]){
                continue;
            }else if(ratings[i] == ratings[i-1]){
                continue;
            }else{
                return INT32_MAX;
            }
            
        }
        // 右规则
        for(int i =0 ; i < ratings.size()-1;i++){
            if(ratings[i] > ratings[i+1] && resu[i] > resu[i+1]){
                continue;
            }else if(ratings[i] < ratings[i+1] && resu[i] < resu[i+1]){
                continue;
            }else if(ratings[i] == ratings[i+1]){
                continue;
            }else{
                return INT32_MAX;
            }
        }

        int sum = 0;
        for(auto&i : resu){
            //cout << i << " ";
            sum += i;
        }
        cout << endl;

        return sum;
    }
private:
    void my_print(vector<int>&nums)
    {
        for(int i = 0 ; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    
};

class Solution{
public:
    int candy(vector<int>& ratings)
    {
        int N = ratings.size();
        vector<int>left(N,1);
        vector<int>right(N,1);
        for (int  i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }
        for(int i = ratings.size()-1  ; i >= 1; i--){
            if(ratings[i-1] > ratings[i]){
                right[i-1] = right[i] +1;
            }
        }
        int sum = 0;
        for(int i = 0 ; i < N ;i++){
            left[i] = max(left[i],right[i]);
            sum += left[i];
        }
        return sum;

        
    }
};
int main()
{
    Solution s1;
    vector<int> nums = {1,3,2,2,1};
    //cout << "main resu= " << s1.candy(nums) << endl;
    cout << " " << s1.candy(nums) << endl;
    return 0;

}