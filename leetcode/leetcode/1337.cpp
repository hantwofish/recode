#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> data; //存储计算结果
        vector<int> resu;
        int row = mat.size();
        int cal = mat[0].size();
        int sum = 0;
        for(int i = 0 ; i < row ; i++){
            sum = 0;
            for(int j = 0 ; j < cal ; j++){
                if(mat[i][j] == 0){
                    break;
                }
                sum++;
            }
            data.push_back(sum);
        }
        vector<int> data_store = data;
        sort(data_store.begin(),data_store.end());
        for(int i = 0 ; i < k ; i++){
            for(int j =0 ; j < data.size(); j++){
                if(data_store[i] == data[j] && find(resu.begin(),resu.end(),j) == resu.end() ){
                    resu.push_back(j);
                    break;
                }
            }
        }
        cout << " resu.size()=   " << resu.size() << endl;

        return resu;





    }
};

int main()
{
    vector<vector<int>>nums = { {1,0,0,0},
                                {1,1,1,1},
                                {1,0,0,0},
                                {1,0,0,0}};
    int k = 1;
    Solution s1;
    vector<int>resu = s1.kWeakestRows(nums,k);
    for(int i = 0 ; i < resu.size(); i++){
        cout << " " << resu[i] ;
    }

    return 0;



}