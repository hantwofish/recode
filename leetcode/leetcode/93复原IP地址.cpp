#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution2 {
private:
    vector<string> result;// 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            } else break; // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() > 12) return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
    void printVec(vector<string>nums)
    {
        for(int i = 0 ; i< nums.size(); i++){
            cout << nums[i] << endl;
        }
    }
};

class Solution {
public:
    void printVec(vector<string>nums)
    {
        for(int i = 0 ; i< nums.size(); i++){
            cout << nums[i] << endl;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        string track = "";
        BackTrack(s, track, 0 , 0);
        return result;
    }
private:
    vector<string> result;
    void BackTrack(string originStr, string &track, int startIndex, int pointNumber)
    {
      //  cout << "func BackTrack" << endl;
        if(pointNumber == 3){
           // cout<< "OK" << endl;
            if(IPisVaild(originStr, startIndex,  originStr.size()-1)){
                //track += '.';
                track += originStr.substr(startIndex, (originStr.size()-1 - startIndex +1) );
                result.push_back(track);
                return;
            }

        }
        for(int i = startIndex; i < originStr.size(); i++){
            if( IPisVaild(originStr, startIndex, i)){
                int lengthStr = i-startIndex +1;
          //      cout << "length = " << lengthStr << endl;
            //    cout << "subStr= " << originStr.substr(startIndex, lengthStr ) << endl;
               
                track += originStr.substr(startIndex, lengthStr );
                track += '.';
                pointNumber++;
                // 回溯
                BackTrack(originStr, track, i +1 ,pointNumber);
                pointNumber--;
                track.erase(track.size()-lengthStr); 

            //     cout << "********" << endl;
            //    cout << "delete point before" << endl;
            //    cout << "track= " << track << endl;
            //     track.erase(track.size()- lengthStr, lengthStr);
            //      cout << "delete point behind" << endl;
            //    cout << "track= " << track << endl;
            //    cout << "********" << endl;
              
            //     // 删除点
            //    // cout << "********" << endl;
            //    // cout << "delete point before" << endl;
            //    // cout << "track= " << track << endl;
            //     track.erase(track.size()-1 , 1);
                
              //  cout << "delete point behind" << endl;
              //  cout << "track= " << track << endl;
              //  cout << "********" << endl;
            }else break;
        }

    }
    bool IPisVaild3(string &s, int startIndex, int endIndx)
    {
        string IP = s.substr(startIndex, (endIndx - startIndex +1));
        if(IP.size() > 3 || IP[0] == '0'){
            return false;
        }
        int IPValue = stoi(IP);
        if(IPValue > 255){
            return false;
        }
    //    cout << "func IPisVaild" << endl;
        return true;
    }
    bool IPisVaild(string &s, int start, int end)
    {
                if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    string str = "101023"; // 25525511135
    vector<string> resu = s1.restoreIpAddresses(str);
    s1.printVec(resu);
    return 0;
}