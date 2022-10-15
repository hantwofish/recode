#include<iostream>
#include<vector>
using namespace std;

class Solution{

public:
    vector<vector<int>> main_process(const vector<vector<int>>&grid, const vector<int>& priory)
    {
        init(grid,priory);
        CalArraySort(nums, priory_arry);
        return nums;

    }
public:
    void init(vector< vector<int>>grid, vector<int> priory)
    {
        nums = grid;
        priory_arry = priory;
    }
    void Print_array(vector<vector<int>>&nums)
    {
        for(int i= 0 ; i< nums.size(); i++){
            for(int j = 0; j < nums[0].size(); j++){
                cout<< nums[i][j] << " ";
            }
            cout << endl;
        }
    }
    void CalArraySort(vector<vector<int>>&nums, vector<int>&priory_arry)
    {
       
        for(int i = 0; i < nums.size() -1 ; i++){
            for(int j = i+1; j< nums.size(); j++){
                     int k = 0;
                     int col = priory_arry[k];
                     if(nums[i][col] > nums[j][col]){
                        swap(nums[i], nums[j]);
                     }else if(nums[i][col] == nums[j][col]){
                        int ll = 0,  rr = 0;

                        while(k < priory_arry.size() && ll == rr){
                            ll += nums[i][priory_arry[k]];
                            rr += nums[j][priory_arry[k]];
                            if(ll > rr){
                                swap(nums[i], nums[j]);
                                break;
                            }
                            k++;
                        }

                     }
                
               
            }
        }
    }

private:
    vector<vector<int>>nums;
    vector<int>priory_arry;

};

int main()
{
    Solution s1;
   const vector<vector<int>>nums = {
       { 1, 3 ,4, 2},
       { 2 ,3, 2 ,7},
       { 3, 3 ,2 ,2},
       { 4, 1, 2, 4}
    };
    const vector<int>prity = {1,3};
    vector<vector<int>> resu = s1.main_process(nums, prity);
    s1.Print_array(resu);

    return 0;
}
