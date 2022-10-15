#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool m_sort(pair<int,int>& A, pair<int,int> & B){
    return (A.first * B.second)< (A.second * B.first);
}
class Solution {
public:

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>> m_vec;
        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = i+1 ; j < arr.size(); j++){
                m_vec.push_back({arr[i], arr[j]});
            }
        }
        sort(m_vec.begin(),m_vec.end(),m_sort);

        for(int i = 0 ; i < m_vec.size() ; i++){
            cout << " " << m_vec[i].first << " " << m_vec[i].second << endl;
        }

        return {m_vec[k-1].first, m_vec[k-1].second};



    }
};

int main()
{
    Solution s1;
    vector<int> arr = {1,2,3,5}; 
    int k = 3;
    vector<int>resu = s1.kthSmallestPrimeFraction(arr, k);
    cout << " " << resu[0] << " " << resu[1] << endl;
    return 0;
}