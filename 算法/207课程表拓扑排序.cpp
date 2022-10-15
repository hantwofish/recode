#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        return true;
    }
};

int main()
{
    Solution s1;
    int numCourses;
    vector<vector<int>> prerequisites;
    bool resu= s1.canFinish(numCourses,prerequisites);
    if(resu){
        cout << "True" << endl;
    } else{
        cout << "False" << endl;
    }
    return 0;
}