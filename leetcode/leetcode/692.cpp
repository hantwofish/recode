#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;
// 仿函数
bool compare(const pair<string, int>& s1, const pair<string, int>&s2){
    // 频率相等，按字母顺序排列
    if(s1.second == s2.second)
        return s1.first < s2.first;
    else
        return s1.second > s2.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int word_size = words.size();
        unordered_map<string , int >store_data;
        for(int i = 0 ; i < word_size ; i++ ){
            store_data[words[i]]++; // 存在哈希表里面
        }
        // 把 map 表存vector中
        vector<pair<string, int>> res ( store_data.begin(),store_data.end() );
        // 按照自定义排序函数进行排序
        sort(res.begin(), res.end() , compare ); 
        // 取出 前 K 个
        vector<string>result;
        for(int i = 0 ; i < k ; i++){
            result.push_back(res[i].first);
        }
        return result;
       
    }
};

int main()
{
    vector<string> data = {"i", "love", "leetcode", "i", "love", "coding"};
    
    int k = 2;
    Solution s1;
    vector<string> resu = s1.topKFrequent(data , k);
    for(auto& i : resu ){
        cout << " " << i ;
    }

    
    return 0;
}