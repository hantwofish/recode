// https://blog.csdn.net/weixin_41010318/article/details/119941697?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-1.searchformbaiduhighlight&spm=1001.2101.3001.4242
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
using namespace std;

bool prim(int A, int B)
{
    int min_num = min(A,B);
    for(int i =2 ; i <= min_num ; i++){
        if( A%i == 0 &&  B%i ==0 ){
            return false;
        }
    }
    return true;

}

int cal_cell(int A, int B)
{
    int left_num = A;
    int righ_num = B;
    for(int i = left_num ; i <= B ; i++){
        for(int j = i + 1 ; j <= B ; j++){
            if(!prim(i,j) ){
                continue;
            }
            int three_num = sqrt(i*i + j*j);
            if(three_num < B && i*i+ j *j == three_num*three_num){
                if(prim(i,three_num) && prim(j,three_num)){
                    cout << i << " " << j << " " << three_num << endl;
                }
                
            }
        }
    }
    return 0;
}
int main()
{
    cal_cell(1, 20);
    return 0;
}