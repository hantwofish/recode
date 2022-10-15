#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;
int cal_resu(int N , vector<int>&student, vector<vector<int>>& up_down);
int main()
{
    // 数据初始化
    int N; // 总的层数
    cin >> N;
    vector<int>student(N+1,0);// 每层学生人数
    for(int i = 1 ; i<= N;  i++){
        int temp ;
        cin >> temp;
        student[i] = temp;
    }
    vector<vector<int>> up_down(N+1,vector<int>(2,0));
    for(int i = 1 ; i <= N ; i++){
        int temp1 , temp2;
        cin >> temp1 >> temp2;
        up_down[i][0] = temp1;
        up_down[i][1] = temp2;
    }
    // 计算
    int resu = cal_resu(N,student,up_down);
    cout << "resu= " << resu << endl;
    return 0;


}

int cal_resu(int N , vector<int>&student, vector<vector<int>>& up_down)
{
    int num = N;
    int resu = INT32_MAX;
    // 楼层遍历
    for(int i = 1 ; i <= N ; i++){
        int temp = 0;
        // 上升的楼层
        for(int up = 1 ; up < i ; up++){
            temp += student[i]*(i-up)*up_down[up][0];
        }

        // 下降的楼层
        for(int down = N ; down >= i +1 ; down--){
            temp += student[down] * (down - i ) * up_down[down][1];
        }
        resu = min(resu,temp);

    }
    return resu;
}