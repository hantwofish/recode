#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        string start ="0000";
        queue<string> que;
        set<string> visited;

        int step =0;

        que.push(start);
        visited.insert(start);
        while (!que.empty())
        {
            int que_size = que.size();
            for(int i= 0 ; i< que_size ; ++i)
            {
                string cur = que.front();
                que.pop();
                if(  find(deadends.begin(),deadends.end(),cur) != deadends.end()       )
                    continue;
                if( cur  == target)
                    return step;


                // 把相邻的八种状态添加进队列
                for(int j = 0; j < 4 ; j++)
                {
                    string add_num = num_add( cur,j );
                    string des_num = num_des(cur,j);
                    if( find(visited.begin(),visited.end(),add_num ) == visited.end()    )
                    {
                        que.push(add_num);
                        visited.insert(add_num);
                    }
                    if( find(visited.begin(),visited.end(),des_num ) == visited.end()    )
                    {
                        que.push(des_num);
                        visited.insert(des_num);
                    }
                        
                }
                

            }
            cout << "que.size()=  " << que.size() <<endl;
            step++;
        }
        return -1;
    }
    string num_add(string str, int j) //在 str 的 j 位置加一
    {
        if( str[j] == '9' )
        {
            str[j] = '0';
        }
        else
            str[j] += 1;
        return str;
    }
    string num_des(string str, int j) //在 str 的 j 位置加一
    {
        if( str[j] == '0' )
        {
            str[j] = '9';
        }
        else
            str[j] -= 1;
        return str;
    }
};


int main()
{
    Solution s1;
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    int resu = s1.openLock(deadends,target);
    cout << "resu =  " << resu << endl;
  //  cout << s1.num_add("9000",0);


    return 0;
}