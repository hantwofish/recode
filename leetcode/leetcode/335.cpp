#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        unordered_set<string> data_set;
        int start_row = 0;
        int start_col = 0;
        data_set.insert(to_string(0) + "," + to_string(0));

        for(int i = 0  ;i < distance.size(); i++){
            //
            
            if( i % 4 == 0){  // 向上
                for(int k = 1 ; k <= distance[i] ; k++){
                    string temp = to_string(start_row) + "," + to_string(start_col + k);
                    if(data_set.find(temp) != data_set.end()){ // find
                        return true;
                    }else{
                        data_set.insert(temp);
                    }
                }
                // 更新
                start_col = start_col + distance[i];


            }else if(i % 4 == 1){ // 向左
                for(int k = 1 ; k <= distance[i] ; k++){
                    string temp = to_string(start_row - k) + "," + to_string(start_col );
                    if(data_set.find(temp) != data_set.end()){ // find
                        return true;
                    }else{
                        data_set.insert(temp);
                    }
                }
                // 更新
                start_row  = start_row - distance[i];

            }else if(i % 4 == 2){ // 向下
                for(int k = 1 ; k <= distance[i] ; k++){
                    string temp = to_string(start_row) + "," + to_string(start_col - k);
                    if(data_set.find(temp) != data_set.end()){ // find
                        return true;
                    }else{
                        data_set.insert(temp);
                    }
                }
                // 更新
                start_col = start_col - distance[i];

            }else if(i % 4 ==3){ // 向右
                for(int k = 1 ; k <= distance[i] ; k++){
                    string temp = to_string(start_row + k) + "," + to_string(start_col );
                    if(data_set.find(temp) != data_set.end()){ // find
                        return true;
                    }else{
                        data_set.insert(temp);
                    }
                }
                // 更新
                start_row = start_row + distance[i];

            }


        }
        return false;
    }
};


int main()
{
    Solution s1;
    vector<int>nums = {1,1,1,1};
    cout << (s1.isSelfCrossing(nums) ? "TRUE" : "FALSE") << endl;
    return 0;
}