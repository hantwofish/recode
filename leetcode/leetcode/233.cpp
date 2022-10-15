#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        string str_num = to_string(n);
        if(n <= 0 ){
            return 0;
        }
        if(str_num.length() ==1 ){
            return 1;
        } 
        vector<int>data(str_num.length(), 0); // 依次存储各个位置 1的 个数
        
        for(int i =0 ; i < str_num.length() ; i++){
            int cur_num = str_num[i] - '0';
            string fronn_str = str_num.substr(0,i-1-0+1);
            string behind_str = str_num.substr(i+1, str_num.length()-1 - (i+1) +1);
            // 当前位前面小于的部分
            int num_1 = 0; 
            if(fronn_str.empty()){
                num_1 = 0;
            }else{
                num_1 = stoi(fronn_str)*pow(10,str_num.length()-1 -i);
            }
            // 
            int num_2 = 0;
            if(cur_num == 0){
                num_2 = 0;
            }else if(cur_num == 1){
                if(behind_str.empty()){
                    num_2 = 1;
                }else{
                    num_2 = 1 * (stoi(behind_str)+1);
                }
                
            }else if(cur_num > 1){
                num_2 = 1 * pow(10, str_num.length()-1 -i);
            }
            data[i] = num_1 + num_2;
            cout << "i= " << i << " num_1= " << num_1 << " num_2= "<< num_2 << endl;

            

        }

        int sum = 0;
        for(auto&i : data){
            sum += i;
        }

        return sum;
    }
};
int main()
{
    int n = 11 ;
    Solution s1;
    int resu = s1.countDigitOne(n);

    
    cout << "main resu= " << resu << endl;
}