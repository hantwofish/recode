#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> data(6,0);
        data[0] = cal_distance(p1, p2);
        data[1] = cal_distance(p1, p3);
        data[2] = cal_distance(p1, p4);
        data[3] = cal_distance(p2, p3);
        data[4] = cal_distance(p2, p4);
        data[5] = cal_distance(p3, p4);
        for(int i = 0; i < data.size() ; i++){
            cout << " data= " << data[i] << endl; 
            if(data[i] == 0){
                return false;
            }
            m1[data[i]] ++;

        }
        cout << " m1.size()= " << m1.size() << endl;
        auto iter = m1.begin();
        int data1 = iter->second ;
        int data2 = (++iter)->second;
        cout << "data1= " << data1 << " data2= "<< data2 << endl;
        if( m1.size() == 2 && (  (data1 == 2 && data2 == 4)   || (data1 == 4 && data2 == 2)    ) )
        {
            return true;
        }

        return false;
    }

    // 计算两点之间距离的平方
    int cal_distance(vector<int>& p1, vector<int>& p2)
    {
        int distace = 0;
        distace  = (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        return distace;

    }
    unordered_map<int, int> m1;
};


int main()
{
    Solution s1;
    vector<int>p1 ={0,0};
    vector<int>p2 ={1,1};
    vector<int>p3 ={1,0};
    vector<int>p4 ={0,1};

    bool result  = s1.validSquare(p1,p2,p3,p4);
    
    cout << "result= " << result << endl;

    return 0;


}

