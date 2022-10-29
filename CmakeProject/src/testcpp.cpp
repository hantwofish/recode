#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row-1;
        int left = 0;
        int right = col -1;
        int i = 0;
        int j = 0;
        //cout << "debug" << endl;
        while(true){
            if(result.size() == row * col){
                break;
            }
            // 从左向右
            i = top;
            j = left;
            for(j = left ; j <= right; j++){
                if(matrix[i][j] != INT32_MAX){
                    result.push_back(matrix[i][j]);
                    matrix[i][j] = INT32_MAX; // 访问过 用 INT_MAX 填充
                }
                
            }
            top++; // 判断是否越界
            if(top > bottom ){
                break;
            }
            //cout << "debug" << endl;
            // 从下到上
            j = right;
            i = top;
            for(i = top ; i <= bottom ; i++){
                if(matrix[i][j] != INT32_MAX){
                    result.push_back(matrix[i][j]);
                    matrix[i][j] = INT32_MAX; // 访问过 用 INT_MAX 填充
                }
            }
            right--;
            if(right < left){
                break;
            }
            // 从右向左
            i = bottom;
            j = right;
            for(j = right ; j >= left ; j--){
                if(matrix[i][j] != INT32_MAX){
                    result.push_back(matrix[i][j]);
                    matrix[i][j] = INT32_MAX; // 访问过 用 INT_MAX 填充
                }
            }
            bottom--;
            if(bottom < top){
                break;
            }
            // 从下到上
            j = left;
            i = bottom;
            for(i = bottom ; i >= top ; i--){
                if(matrix[i][j] != INT32_MAX){
                    result.push_back(matrix[i][j]);
                    matrix[i][j] = INT32_MAX; // 访问过 用 INT_MAX 填充
                }
            }
            left++;
            if(left > right){
                break;
            }
            cout << "size= " << result.size() << endl;
        }


        return result;
    }
private:
    vector<int>result;
};

int main()
{
    vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s1;
    vector<int>resu = s1.spiralOrder(matrix);
    for(auto& i : resu){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}