#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int pre1 = 0;
        int pre2 = slow;
        while(pre1 != pre2){
            pre1 = nums[pre1];
            pre2 = nums[pre2];
             
        }
        return pre1;

    }
};

int main()
{
    Solution s1;
    vector<int>nums ={1,3,4,2,2};
    vector<int>::iterator it = nums.begin();
    cout << *it << endl;
    int resu = s1.findDuplicate(nums);
    cout << "main resu= " << resu << endl;
    return 0;
}