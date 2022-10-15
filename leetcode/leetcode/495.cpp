#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int resu = 0;
        for(int i = 0 ; i < timeSeries.size(); i++){
            if( i == timeSeries.size()-1){
                resu += duration;
                break;
            }
            int next = timeSeries[i+1];
            if(next >= timeSeries[i] + duration){
                resu += duration;
            }else{
                resu = resu + (next - timeSeries[i]);

            }
        }
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>timeSeries= {1,2};
    int durtion = 2;
    int resu = s1.findPoisonedDuration(timeSeries,durtion);
    cout <<  "resu = " << resu << endl;
    return 0;
}