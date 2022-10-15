#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 约瑟夫环问题

int cal(int M , int N){ // N 个人，报数为 M 的出圈
    int target = M;
    vector<int>data(N+1,0);
    for(int i = 1 ; i <= N; i++){
        data.push_back(i);
    }
    int num = 1;
    int count = 0;
    int i = 1;
    for(i = 1; ; i++){
        cout << "i= " << i << endl;
        if(data[i] == 0){
            continue;
        }
        num++;
        if(num == M){
            count++;
            if(num == N){
                break;
            }
             printf("No%d: %d\n",count , data[i]);
            data[i] = 0;
            num = 0;
        }
        if(i == N){
            i = 1;
        }


    }
    printf("Last No is:%d " , data[i]);
    return 0;


}



int cal2(int M, int N) // N 个人， 删除 M
{
    vector<int>data(N,0);
    for(int i =0 ; i < N ; i++){ // 如果当前位置已经被排除，则赋值为 INT_MIN
        data[i] = i;
    }
    // 
    for(auto& i : data){
        cout << " " << i ; 
    }
    cout << endl;

    //
    int number = 0;
    int count = 0;
    int i = 0;
    while(1){
        if(data[i] != INT32_MIN){
            number++;
            if(number == M){
                count++;
                if(count == N){
                    break;
                }
                cout << "No" << count << " " << data[i] << endl;   
                data[i] = INT32_MIN;
                number = 0;             
            }
        }
        i++;
        if( i == N){
            i = 0;
        }
       

    }
    cout << "last= " << data[i] << endl;
    return 0;

}

int main()
{
    int N = 5;
    int mod_num  = 3;
    int resu = cal2(mod_num, N);
    cout << "RESU= " << resu << endl;
    return 0;
}