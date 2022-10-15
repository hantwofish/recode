#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 多起点的固定长度滑动窗口
    vector<int> findSubstring(string s, vector<string>& words) {
        int N = s.length();
        int M = words.size();
        int D = words[0].length();
        int L = M * D; // 滑动窗口宽度， 每次窗口以 D 向前
        unordered_map<string ,int> target;
        for(auto i : words){
            target[i]++;
        }
        cout << "target.size()= " << target.size() << endl;

        for(int startr_location = 0; startr_location < D ; startr_location ++ ){ // 多个窗口起点(0-D-1)
           
            unordered_map<string , int> cur_hash;
            // 先对 cur_hash 进行初始化
            string str_init = s.substr(startr_location, L);
            cout << "str_init= " << str_init << endl;
            for(int i = 0 ; i  < str_init.length()  ; i= i+ D ){
                if(  find(words.begin(),words.end(), str_init.substr(i,D)) != words.end()  ){
                    cur_hash[str_init.substr(i,D)]++;
                }
            }
            if(cur_hash == target){
                res.push_back(startr_location);
                
            }




            for(int i = startr_location + D ; i + L <= N ; i=i+D){
                // 窗左单词，窗右单词；
                cout << "***" <<endl;
                string str_left = s.substr(i-D,D);
                string str_right = s.substr(i+L-D,D);
                if(find(words.begin(),words.end(),str_left) != words.end()){
                    cur_hash[str_left]--;
                    
                }
                if(find(words.begin(),words.end(),str_right) != words.end()){
                    cur_hash[str_right]++;
                }
                if(cur_hash == target){
                    res.push_back(i);
                }
                

            }

        }


        return res;
    }
private:
    vector<int>res;
};

void test()
{
    unordered_map<string,int>A;
    A.insert({"giid",2});
    A.insert({"geid",3});
    A.insert({"geed",46});
    unordered_map<string,int>B;
    B.insert({"geed",46});
    B.insert({"geid",3});
    B.insert({"giid",2});
    B.insert({"dddd",222});
    
    
    if(A==B){
        cout << "equal" << endl;
    }else{
        cout << "not equal " << endl;
    }


}

int main()
{
    // test();
    //return 0;
    Solution S1;
    string s = "wordgoodgoodgoodbestword";
    vector<string>words = {"word","good","best","good"};
    vector<int> resu = S1.findSubstring(s,words);
    for(auto& i : resu){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
