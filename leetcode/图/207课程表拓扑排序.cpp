#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> figureData(numCourses);
        // 记录入度
        vector<int>deg(numCourses);
        for(auto i: prerequisites){
            int  a = i[1];
            int b = i[0];
            figureData[a].push_back(b);
            deg[b]++;
        }
        queue<int> que;
        // 将入度为 0 的放到 队列中
        for(int i = 0; i< numCourses; i++){
            if(deg[i] == 0){
                que.push(i);
            }
        }

        int cnt = 0 ;
        while(!que.empty()){
            int curCourseID = que.front();
            que.pop();
            cnt++;
            for(int i = 0; i< figureData[curCourseID].size(); i++){
                // 所有要修 curCourseID 课程的 入度 都要减一
                int temp = figureData[curCourseID][i];
                deg[temp]--;
                if(deg[temp] == 0){
                    que.push(temp);
                }

            }


        }

        return cnt == numCourses;
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