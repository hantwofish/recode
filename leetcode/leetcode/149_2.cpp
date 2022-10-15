#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int N = points.size();
        for(int i = 0 ; i < points.size(); i++){
            for(int j = i+ 1; j < points.size(); j++){
                // 计算斜率
                // 斜率为 无穷
                int temp = 2;
                if(points[i][0] == points[j][0]){
                    for(int k = j + 1; k < points.size(); k++){
                        if(points[k][0] == points[i][0]){
                            temp++;
                        }
                    }
                    resu = max(resu, temp);
                    if(resu > points.size()/2){
                        return resu;
                    }
                    continue;

                }else if(points[i][1] == points[j][1]){ // 斜率为 0
                    for(int k = j + 1; k < points.size(); k++){
                        if(points[k][1] == points[i][0]){
                            temp++;
                        }
                    }
                    resu = max(resu, temp);
                    if(resu > points.size()/2){
                        return resu;
                    }
                    continue;
                }
                // 斜率为 其他
                for(int k = j+1; k < points.size(); k++){
                    int a = points[j][1] - points[i][1];
                    int b = points[j][0] - points[i][0];
                    int c = points[k][1] - points[i][1];
                    int d = points[k][0] - points[i][0];
                    if( a *d ==  b *c){
                        temp++;
                    }
                }
                resu = max(resu, temp);
                if(resu > points.size()/2){
                    return resu;
                }
                    
            }
        }
        return resu;

    }
private:
    int resu = INT32_MIN;
};

int main()
{
    Solution s1;
    vector<vector<int>>nums = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << " " << s1.maxPoints(nums) << endl;
    return 0;
}