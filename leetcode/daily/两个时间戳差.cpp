#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

// 输入两个时间戳，返回两个时间之间的差值(分钟) "20:23" ," 06: 45"
/*
20:23  06:00 分两种情况 06:00  - 20:23  或者 20：23 - 06：00
对于两个时间戳，分三种情况，、、
1. 两个时间戳在同一天内
2. str1 比 str2 早一天
3. str2 比 str1 早一天
取三种情况最小值 
*/


int calcu(string str1, string str2  )
{
    int str_len = str1.length();
    int str1_hour = stoi( str1.substr(0,2) );
    int str1_min =  stoi( str1.substr(3,2) );
    int str2_hour =  stoi( str2.substr(0,2) );
    int str2_min =  stoi( str2.substr(3,2) );

    // 在同一天
    int res1 = abs( str1_hour * 60 + str1_min - ( str2_hour * 60 + str2_min ) );
    int res2= abs( (24-1- str1_hour ) * 60 + 60 - str1_min + (str2_hour * 60 + str2_min ));
    int res3 = abs( (24- 1 -str2_hour ) * 60 + 60 - str2_min + (str1_hour * 60 + str1_min ));

    cout << "in one day " << res1 << " another day " << res2 << " " << res3 << endl;

    res1 = min(min(res1, res2),res3);
    return res1;

}

int main()
{
    string str1 = "00:20";
    string str2 = "01:40";
    int res = calcu(str1,str2);
    cout << "min gap =  " << res << endl;
    return 0;
}