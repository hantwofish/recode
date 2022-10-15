#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
    string cal(int n, int k)
    {
        vector<bool> is_visited(n,false);
        backtracing(n,0, is_visited , k);
        return result[k-1];
    }
    void backtracing( int n  , int start , vector<bool>&is_visited, int k  )
    {
        if(mid_str.length()== n)
        {
            result.push_back(mid_str);
            if(result.size()== k)
                return;
            return;
        }
            
        for(int i = 0 ; i < n ; i++)
        {

            if(is_visited[i])
                continue;
            mid_str += (i+1+ '0');
            is_visited[i] = true;
            cout << "mid_str= " << mid_str << endl;
            backtracing(n,i +1,is_visited, k);
            mid_str.pop_back();
            is_visited[i] = false;

        }
    }
    void my_print()
    {
        for(int i = 0 ; i< result.size(); i++)
        {
            cout << " " << result[i] << " ";
        }
        cout << endl;
    }
public:
    vector<string> result;
    string mid_str;


};

int main()
{
    int N = 3, k =4;
    Solution s1;
   
    cout << s1.cal(N,k) << endl;
    return 0 ;
}