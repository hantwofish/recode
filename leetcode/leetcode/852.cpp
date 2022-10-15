#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int cur = arr[0];
        int next = 0;
        for(int i = 1 ; i < arr.size() ; i++){
            next = arr[i];
            if(next > cur){
                cur = next;
            }else if(next < cur){
                return i;
            }

        }
        return 0;

    }
};


int main()
{

}