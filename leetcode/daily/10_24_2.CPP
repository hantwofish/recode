#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace  std;
int cal(vector<vector<int>>&data, int row, int col ,int width);
int main()
{
    int T;
    cin >> T;
    for(int i = 0 ; i < T;i++){
        int N ;
        int M;
        cin >> N >> M;
        vector<vector<int>>datas(N,vector<int>(M,0));
        for(int j = 0 ; j < N; j++){
            for(int k =0 ; k < M; k++){
                int temp;
                cin >> temp;
                datas[j][k] = temp;

            }
        }
    //    cout << "data[3][3]= "<< datas[3][3] << endl;
        int resu = INT32_MIN;
        // 进行计算
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                for(int width = 1 ; width <= min(N,M) ; width++){
                    resu = max(resu,cal(datas,i,j,width));
                   
                }
            }
        }
        cout  << resu <<endl;
    
    }
}

int cal(vector<vector<int>>&data, int row, int col ,int width)
{
    // 是否超出边界
    if((row + width > data.size()) || (col + width > data[0].size())){
        return INT32_MIN;
    }

    // 
    int sum = 0;
    for(int i= row ; i < row + width ; i++ ){
        for(int j = col; j < col + width ; j++){
            if(data[i][j] == -1){
                return INT32_MIN;
            }
            sum += data[i][j];
        }
    }
   // cout << "SUM= " << sum << endl;
    return sum;
}