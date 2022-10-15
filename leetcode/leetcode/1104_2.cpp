// 二叉树寻路
#include<stdbool.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int getReverse(int label, int row) 
    {
        return (1 << row - 1) + (1 << row) - 1 - label;
    }


    vector<int> pathInZigZagTree(int label) 
    {
        int num = label;
        int mid_num;
        int row = get_row(num);
      //  resu.push_back(label);
        if(row %2 == 0){
            num = (pow(2,row -1) + pow(2,row)-1  )- num ;
        }
        while(num  >=  1){

            if(row %2 == 0){
                
                mid_num = (pow(2,row -1) + pow(2,row)-1  )- num ;
                resu.push_back(  mid_num );
                //num = mid_num;
            }
            else{
                resu.push_back(num);
            }
            // resu.push_back(num);
            cout << "data= " << num << " row= "<< row << endl;
            num = num / 2;
            row--;
        }
        
        reverse(resu.begin(),resu.end());
        return resu;
    }
    
    int get_row(int val)
    {
        for(int i = 1 ; i <= val; i++){
            if( pow(2,i-1) <= val && val <= pow(2,i)-1 ){
                return i;
            }
        }
        return 0;
    }
public:
    vector<int> resu; // 先存储从左到右的编号（一般二叉树），后进行反转
};

int main()
{
    int val = 14;
    Solution s1;

    vector<int >resu = s1.pathInZigZagTree(val);

    for(int i = 0; i < resu.size(); i++){
        cout << " " << resu[i] << " ";
    }
    return 0;
}
