/*
 * @Author: your name
 * @Date: 2021-06-24 13:34:39
 * @LastEditTime: 2021-06-24 16:49:22
 * @LastEditors: Please set LastEditors
 * @Description: leetcode 129 超出时间限制
 * @FilePath: \leetcode\code\149.cpp
 */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        vector<vector<int>> point_store; // 用于存储共线点的坐标
        for(int i = 0 ; i < points.size(); i++)
        {
            point_store.clear();
            // 优化 
            if(resu > points.size()/2  || resu > points.size() - i)  
            {
                //cout << "resu = " << resu << "**" << endl;
                return resu;
            }
            backtracing(points, i , point_store);
        }
        return resu;
    }
    void backtracing(vector<vector<int>>&points , int start_location , vector<vector<int>>& point_store)
    {

       
        // 终止条件；、
        if(start_location > points.size())
            return;
        // 选择列表
        for(int i  = start_location ; i < points.size() ; i++)
        {
           // cout <<  "i= " << i << endl;
           
           
            if(point_store.size() <2) 
            {
                point_store.push_back(points[i]);
                int cur_szie = point_store.size();
                resu = max(resu , cur_szie);
                backtracing(points, i+1 ,point_store);
                point_store.pop_back();
                continue;
                
            }
          //  cout << "backtracing " << endl;
            int a = point_store[0][0] , b = point_store[0][1] , c = point_store[1][0] , d = point_store[1][1];
            int e = points[i][0] , f = points[i][1] ;
           // cout << "**" << endl;
           // cout << " a= " << a << " b= " << b << " c= " << c  << " d= " << d << " e= " << e << " f= " << f << endl;
            if( (d-b)*(e-a) == (c-a)*(f-b) ) // 当前点 满足斜率
            {
                point_store.push_back(points[i]);
                int cur_szie = point_store.size();
                resu = max(resu , cur_szie);

                    

                    
                backtracing(points , i +1 , point_store);
                point_store.pop_back(); 
                
            }
            else // 判断下一个点
                continue;
        }
    }
    // void my_print(vector<vector<int>>& points)
    // {
    //     for(int i =0 ; i < points.size();i++)
    //     {
    //         cout << "i= " << i <<  " [" <<  points[i][0] << " " <<points[i][1] << " ]" <<  " " ;
    //     }
    // }


private:
    int resu = 0;
    int mid_resu = 0;

};

int main()
{
    // vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<vector<int>> points = {{4,-3},{970,680},{-97,-35},{3,8},{60,253},{0,-13},{-270,-748},{-291,-165},{270,890},{90,228},{-220,-270},{-255,-118},{873,615},{-42,-175},{440,345},{4,-9},{170,27},{425,114},{56,203},{531,872},{295,480},{231,193},{291,225},{680,201},{-10,9},{-388,-230},{-385,-127},{-590,-990},{-7,-40},{308,222},{-616,-247},{-70,-283},{150,526},{77,113},{396,304},{-264,-311},{-6,-8},{-88,-147},{30,162},{49,176},{81,196},{-9,-124},{-27,-188},{-14,-67},{308,233},{413,676},{-77,33},{-177,-304},{0,-31},{472,774},{462,313},{-35,-148},{1,-2},{-440,-475},{154,153},{485,355},{-231,-47},{340,85},{-60,-111},{42,149},{-354,-598},{388,290},{44,-24},{3,-8},{510,143},{-308,-352},{-18,-156},{-21,-94},{-63,-316},{-118,-206},{0,73},{-240,-657},{-352,-393},{-531,-892},{-485,-295},{352,263},{616,393},{-154,-7},{3,4},{-5,-9},{63,230},{385,273},{-679,-425},{-595,-234},{-582,-360},{-176,-229},{770,473},{-539,-207},{-56,-229},{-236,-402},{-970,-620},{-425,-176},{240,799},{118,186},{10,-7},{-680,-263},{-5,7},{220,140},{-2,7},{-28,-121},{-300,-839},{-54,-284},{-194,-100},{-308,-87},{-3,-10},{-873,-555},{-90,-202},{-5,-4}};
    Solution s1;
    cout << "main " << points.size() << endl;
    int resu = s1.maxPoints(points);
    cout << "resu= " << resu << endl;
    return 0;
}