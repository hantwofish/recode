#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int removeDuplicates(int* nums, int numsSize)
{
    int* front = nums;
    int cur_num_size = 0;
    int i = 0;
    while(i < numsSize){
        if(i==0){
            cur_num_size = 1;
            i++;
            continue;
        }
        //
        if( *(front + i) == *(front + i -1) && cur_num_size < 2 ){
            cur_num_size++;
            i++;
        }else if( *(front + i) == *(front + i -1) && cur_num_size == 2 ){
            // 删除当前
            for(int j = i + 1 ; j < numsSize ; j++){
                *(front+ j - 1) = *(front + j );
            }
            numsSize--;
        }else if( *(front + i) != *(front + i -1) ){
            cur_num_size = 1;
            i++;
        }



    }
   
    return numsSize;




}

int main()
{
    int nums[] = {0,0,1,1,1,1,2,3,3};
    int num_size = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    for(int i = 0 ; i < num_size ; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << num_size << endl;
    return 0;

}