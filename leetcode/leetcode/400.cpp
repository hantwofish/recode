#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9){
            return n;
        }
        int d= 1 ;
        int count = 9;
        int data = n;
        // 判断属于哪个区间 位数为 d
        while( n > (d * count) ){
            n -= (d * count);
            d++;
            count *= 10;
        }
        cout << "d= " << d << endl;
        // 前 n - 1 位的数字一共count 位
        count  = 0;
        for(int i = 1; i < d ; i++){
            count += (i * 9* pow(10, i-1));
        }
        cout << "count= " << count << endl;


        // 确定为 段内第几个数
        n = data;
        int start = (int)pow(10,d-1); 
        cout << "start= " << start << endl;
        double temp = (n -count)/(d*1.0);
        cout << "temp= " << temp  << " *= " << ceil(temp) << endl;

        int d_time = ceil( temp); // 段内序号 
        cout << "d_time = " <<d_time << endl;


        int d_num = start  + d_time -1;
        cout << "start= " << start <<  " d_num= " << d_num << endl;

        string resu = to_string(d_num);
        int n_time = 0; //  数字内序号
        n_time = (n - count )%d == 0 ? d : (n - count )%d ;
        
        

        return resu[n_time-1]-'0';



    }
};

int main()
{
    Solution s1;
    int n  = 190;
    int resu = s1.findNthDigit(n);
    cout << "resu= " << resu << endl;
    return 0;

}


class Solution {
public:
    int findNthDigit(int n) {
        int d = 1, count = 9;
        while (n > (long) d * count) {
            n -= d * count;
            d++;
            count *= 10;
        }
        int index = n - 1;
        int start = (int) pow(10, d - 1);
        int num = start + index / d;
        int digitIndex = index % d;
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
        return digit;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/nth-digit/solution/di-n-wei-shu-zi-by-leetcode-solution-mdl2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。