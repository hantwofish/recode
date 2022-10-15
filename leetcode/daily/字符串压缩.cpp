#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    string calcular(string str)
    {
        int size_lenth =  str.length();
        int cur = 0;
        int next = cur+1;
        string resu = "";
        string temp =" ";
        string temp_1 =" ";
        while( next < size_lenth )
        {
            if( str[next]  == str[cur])
            {
                next++;
            }
            else if (str[next ] != str[cur])
            {

                temp[0] = next - cur + '0' ;
                temp_1[0] = str[cur];
                resu = resu + temp_1 + temp;
                cur = next;
                next++;
            }
            
        }
        if(next == size_lenth)
        {
            temp[0] = next - cur + '0' ;
            temp_1[0] = str[cur];
            resu = resu + temp_1 + temp;
        }
        
        return resu;


    }
};



int main()
{
 //   cout << "start= " << endl;
    Solution s1;
    string str = "aabcccccaaa";
    string resu =  s1.calcular(str);
    cout << "resu = " << resu << endl;
 
    return 0;
    
}
/* thinking 
扫描当前位置后面的字母，若相同，则前进，不同则计数


*/