#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
找出每个房子最近的 加热器，输出最大的距离
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int resu = INT32_MIN;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        for(int i = 0 ; i < houses.size() ; i++){ 
            //cout << "i= " << i << " " << cal_bound_find(houses[i],heaters) << " " <<cal2(houses[i],heaters) << endl;
            //cal2(houses[i],heaters);
            resu = max(resu , cal_bound_find( houses[i] , heaters));
        }

        return resu;
    }
    // 找出当前 位置，最近的 加热器距离
    int cal(int cur , vector<int>&heaters)
    {
        int distance = abs(cur - heaters[0]);
        for(int i = 0 ; i< heaters.size(); i++){
            if( abs(cur - heaters[i]) <=  distance  ){
                distance = abs(cur - heaters[i]);
            }else{
                return distance;
            }
            
        }
        return distance;
    }
    int cal2(int cur , vector<int>&heaters)
    {
        int distance = INT32_MAX;
        for(int i = 0 ; i< heaters.size(); i++){
            //cout << "i= " << i << " " << abs(cur - heaters[i]) << endl;
            distance = min(distance , abs(cur - heaters[i]));
            
        }
        return distance;
    }
    int cal_bound_find(int cur , vector<int>&heaters)
    {
        int left = 0;
        int right = heaters.size() -1;
        cout << "left= " << left << " right= " << right << endl; 
        // 寻找 cur 的左边界
        while(left <= right){
            
            int mid = (left + right)  /2;
            if( cur == heaters[mid] ){
         
                return 0;
            }else if(heaters[mid] > cur){
            
                right = mid - 1;

            }else if(heaters[mid] < cur){
                left = mid +1;
            }
        }
        // 数组越界
        left = left >= heaters.size() ? heaters.size()-1 : left;
        right = right < 0  ? 0 : right ;
     
        cout << "left= " << left << " right= " << right << endl; 
        int left_val = abs(heaters[left] - cur);
        int right_val = abs(heaters[right] - cur);

        return min(left_val,right_val);
        

    }
};

int main()
{
    Solution s1;
    

    vector<int>houses = {1,2,3};
    vector<int>heaters = {2};
    int resu = s1.findRadius(houses,heaters);
    cout << "main resu= " << resu << endl;
    return 0;
}
