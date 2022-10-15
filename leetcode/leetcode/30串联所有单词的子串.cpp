#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sub_str_lenth = words[0].length();
        int word_size = words.size();
        
        string cur_str = words[0];
        for(int i = 0 ; i < s.length(); i++){
            if( s[i] !=  cur_str[0] || s.substr(i,sub_str_lenth) != cur_str  ){
                continue;
            }
            cout << "i= "<< i << endl;
            vector<bool>visited(word_size, false);
            int index = find(words.begin(), words.end(), s.substr(i,sub_str_lenth)) - words.begin();
            visited[index] = true;

            //vector<bool>visited(words.size(), false);
            // 从  i  的左右开始扩展
            int left = i - sub_str_lenth ;
            int right = i + sub_str_lenth;
            int count = 1; // 等于i 出已经包含
            while(left >= 0){
                if(find(words.begin(), words.end(), s.substr(left,sub_str_lenth)) != words.end()  ){
                    index = find(words.begin(), words.end(), s.substr(left,sub_str_lenth)) - words.begin();
                  
                    if(visited[index]){
                        left += 3;
                        break;
                    }
                    visited[index] = true;
                    count++;
                    
                }
                left -= 3;
            }
            while(right < s.length()){
                if(find(words.begin(), words.end(), s.substr(right,sub_str_lenth)) != words.end()  ){
                    index = find(words.begin(), words.end(), s.substr(right,sub_str_lenth)) - words.begin();
                    if(visited[index]){
                        right -= 3;
                        break;
                    }
                    visited[index] = true;
                    count++;
                    
                }
                right += 3;
            }
            cout << "count= " << count << endl;
            if(count == words.size()){
                cout << "left= "<< left << " i= "<< i << " right= "<< right << endl;
                result.push_back(i);
            }





        }
        return result;

    }

private:
    vector<int>result;
};

int main()
{
    Solution S1;
    string s = "barfoofoobarthefoobarman";
    vector<string>words = {"bar","foo","the"};
    vector<int> resu = S1.findSubstring(s,words);
    for(auto& i : resu){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}