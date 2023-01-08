#include"STLCOMMON.h"
using namespace std;



class Solution {
public:
    vector<int> minOperations(string boxes) {
        for(int i =0 ;i < boxes.length(); i++){
            if(boxes[i] == '1'){
                location.push_back(i);
            }
        }
        resu.resize(boxes.size(),0);
        for(int i =0; i < boxes.length();i++){
            for(int j = 0 ; j < location.size(); j++){
                resu[i] += (abs(i - location[j]));
            }
        }
        PrinVec();

        return resu;


    }
    void PrinVec()
    {
        for(auto i: resu){
            cout << i << " ";
        }
        cout << endl;
    }
public:
    vector<int>location;
    vector<int>resu;
};

int main()
{
    Solution s1;
    string boxes = "001011";
    vector<int>resu = s1.minOperations(boxes);
    return 0;

}