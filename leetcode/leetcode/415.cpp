#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        // 将 两个字符串补成相同长度
        int str1_len = num1.length();
        int str2_len = num2.length();
        string add_zero ="";
        string resu ="";
        for(int i = 0 ; i< abs(str1_len - str2_len) ; i++)
        {
            add_zero += "0";
        }
        if(str2_len < str1_len)
            num2 = add_zero + num2;
        else
            num1 = add_zero + num1;

        // 模拟加法运算
        int lenth = str2_len > str1_len ? str2_len : str1_len ;
        int c= 0; // 表示进位
        int d = 0; // 余数
        for (int i = lenth -1; i >= 0; i--)
        {
            int m = num1[i] - '0';
            int n = num2[i] - '0';
            d = (  m + n    + c ) %10;
            c = ( m +n + c      )/10;

            string da = to_string(d);
            resu = da + resu;
            
        }
        if( c != 0)
        {
            return to_string(c)+ resu;
        }
        return resu;
        

    }
};

int main()
{
    Solution s1;
    string nums1 ="9";
    string num2 = "9";
    cout << s1.addStrings(nums1,num2) << endl;

    return 0;
}