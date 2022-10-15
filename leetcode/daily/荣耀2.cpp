#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool is_prime(int num)
{
    for(int i = 2 ; i < num/2 + 1 ; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}


bool cal(int number)
{
    /*
    if(number == 1){
        return false;
    }
    if(number <=5 ){
        if( is_prime(number)){
            return true;
        }else{
            return false;
        }
    }
    */
    vector<int>data; // 存放素数
    for(int i = 2 ; ; i++){
        if( data.size() == number ){
            break;
        }
        if(is_prime(i)){
            data.push_back(i);
        }
    }
    // 打印素数数组
    for(int i = 0 ; i < data.size(); i++){
        cout << " " << data[i] ;
    }
    cout << endl;

    // 滑动窗口
    int left = 0;
    int right = 0;
    int sum = data[left];
    while(left < data.size() && right < data.size()){
        if(data[left] > number){
            return false;
        }
        
        if(sum  == number){
            cout << " ++" << endl;
            return true;
        }else if(sum  > number){
            sum -= data[left];
            left ++;
        }else if(sum < number){    
            right ++;
            sum += data[right];  
        }
        //cout << " * " << sum ;
    }
    return false;

}

int main()
{
    int test_data =1;
    cout << cal(test_data) << endl;
    return 0;

}