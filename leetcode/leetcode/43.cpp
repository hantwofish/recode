#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) 
    {

        // 保证 num2 位数 小于 num1
        if( num1.size() < num2.size() )
        {
            string data_str = num1;
            num1 =num2;
            num2 = data_str;
        }
        int lenth1 = num1.length();
        int lenth2 = num2.length();


        cout << "num1= " << num1 << " num2= " << num2 << endl;
        int c = 0; // 进位
        int d = 0; //余数
        string temp="";
        string zero = "0";
        string result = "0";
        // 123* 56
        for( int i = lenth2 -1  ; i>= 0 ;i--) // 6-5
        {
            temp ="";
            c= 0;
            int n = num2[i] - '0';
            for(int j = lenth1 - 1; j >= 0; j-- ) // 3 -2- 1
            {
                int m = num1[j] - '0';
                
                d = ( m * n + c) % 10;
                c = (m * n + c) / 10;
                temp = to_string(d) +  temp; 
            }
            if( c != 0 )
                temp = to_string(c) + temp;
            

            // 计算 两个 string 相加
            if( i != lenth2 -1 )
                temp = temp + add_zero(lenth2 - 1 -i);

            cout << "temp  " << temp << endl;  
            


            result = addStrings(result , temp);
            cout << "   result " << result <<endl;

            

        }    

        
        return result;
    }
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

    string add_zero(int m )
    {
        string zero="";
        for(int i = 0 ; i< m ; i++)
        {
            zero = zero + "0";
        }
        return zero;
    }
};


int main()
{
    Solution s1;
    string nums1 ="99";
    string num2 = "999";
    cout <<"-------------------" << endl;
    cout << s1.multiply(nums1,num2) << endl;
  //  cout << " "<< 123*456 <<endl;

    return 0;
}