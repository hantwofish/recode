#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;



class Solution {
public:
    bool isMatch(string s, string p) {
        int s_lenth =s.length();
        int p_lenth = p.length();
        int i =0;
        int j =0;
        int istart = -1; // istart , jstart 分别标记 s 和 p 中 *匹配过的位置
        int jstart = -1;
        if( s_lenth == 0 )
        {
            if(p_lenth == 0) return true;
            for(int i= 0 ; i< p_lenth ; i++)
            {
                if(p[i] != '*' && p[j] != '?')
                    return false;
            }
            return true;
        }



        while ( i < s_lenth   )
        {
          //  cout <<" " << s[i] << " " << p[j] << endl;
            if(  s[i] == p[j] || p[i] == '?' )
            {
                i++;
                j++;
            }
            else if( p[j] == '*' ) // 出现* 号码
            {
                // j++;
                // while( i < s_lenth && s[i]!= p[j] )
                // {
                //      i++;
                // }
                // if( ( i +1 < s_lenth) && s[i] == s[i+1] )
                //     i++;
                istart = i ;
                jstart = j;
                j++;
                   
                // cout << s[i] << " " << p[j]  << endl;
            }
            else if(   istart > -1  )
            {
                i = ++istart;
                j = jstart+1;


            }
            else if( s[i] != p[j] )
                return false;
            
        }
        if(   i >= s_lenth && j >= p_lenth)
            return true;
        else
            return false;
  
    }
};



int main()
{
    /*
    string s = "abcabczzzde";
    string p = "*abc???de*";
    */
    string s = "hello";
    string p = "*ll*";
    Solution s1;
    bool resu = s1.isMatch(s,p);
    cout << "resu =  " << resu  <<endl;

    return 0;



}
/*
public boolean isMatch(String s, String p) {
    if (p==null||p.isEmpty())return s==null||s.isEmpty();
    int i=0,j=0,istart=-1,jstart=-1,slen=s.length(),plen=p.length();
    //判断s的所有字符是否匹配
    while (i<slen){
        //三种匹配成功情况以及匹配失败返回false
        if (j<plen&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='?')){
            i++;
            j++;
        }else if (j<plen&&p.charAt(j)=='*'){
            istart=i;
            jstart=j++;
        }else if (istart>-1){
            i=++istart;
            j=jstart+1;
        }else {
            return false;
        }
    }
    //s中的字符都判断完毕，则认为s为空，此时需要p为空或者p中只剩下星号的时候，才能成功匹配。
    //如果p中剩余的都是*，则可以移除剩余的*
    while (j<plen&&p.charAt(j)=='*')j++;
    return j==plen;
}

作者：jerrymouse1998
链接：https://leetcode-cn.com/problems/wildcard-matching/solution/javashuang-zhi-zhen-tan-xin-he-dong-tai-gui-hua-xi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/