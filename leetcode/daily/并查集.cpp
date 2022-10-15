#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int father[200];
// 将n 个数进行初始化，父节点位本身　
void init(int n)
{
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}
int find(int num)
{
    if(num = father[num]){
        return num;
    }else{
        father[num] = find(father[num]); // 父节点设为根节点
        return father[num];  // 返回父节点
    }
}   
void uion(int i, int j )
{
    int i_father = find(i); // 找到 i的祖先
    int j_father = find(j);  // 找到 j  的祖先
    father[i_father] = j_father; // 将 i 的祖先指向 j 的祖先

}

int main()
{
    int N = 10;
    int M = 7;
    vector<vector<int>>data = {{2,4},{5,7},{1,3},{8,9},{1,2},{5,6},{2,3}};
    int test =3;
    vector<vector<int>>test_data = {{3,4},{7,10},{8,9}};

    init(N);
    for(int i = 0; i <data.size() ; i++){
        uion(data[i][0], data[i][1]);
    }
    //
    for(int i =0 ; i < test_data.size() ; i++){
        if(find(test_data[i][0]) == find(test_data[i][1])){
            cout << "YES" << endl;
        }else{
            cout <<"NO" << endl;
        }

    }
    for(int i =1 ; i <= N; i++){
        cout << find(i) << endl;
    }

    cout << "**" << endl;
    for(int i = 1 ; i <= N ; i++){
        cout << "father["<< i << "]= " << find(i) << endl;
    }
    



    return 0;

}