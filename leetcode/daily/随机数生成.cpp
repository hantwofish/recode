#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

#define random(x) (rand()%x) 

#define N 10 // 生成 0 ~ N 的一个随机数
#define NUMBER_SIZE 10 // 生成 NUMBER_SIZE 个随机数
int main()
{
    srand((int)time(0));
    vector<int>data;
    int count = 0;
    while(data.size()  < NUMBER_SIZE){
        cout << "count= " << count << endl;
        int number = random(N);
        if(find(data.begin(),data.end(),number) == data.end()){
            data.push_back(number);
            count ++;
        }
        
    }

    for(auto i= data.begin(); i != data.end(); i++){
        cout << *i << " " ;
    }
    cout << endl;
    system("pause");
    
    return 0;
}
