#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
            resu.push_back(curCourseID);
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
        if(cnt == numCourses){
            return resu;
        }
        return {};
    }
public:
    vector<int>resu;
};

int main()
{
    Solution s1;
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{2,7,63},{4,3,60},{1,3,53},{5,6,100},{1,4,40},{4,7,95},{4,6,97},{3,4,68},{1,7,75},{2,6,84},{1,6,27},{5,3,25},{6,2,2},{3,7,57},{5,4,2},{7,1,53},{5,7,35},{4,1,60},{5,2,95},{3,5,28},{6,1,61},{2,5,28}};
    vector<int> resu = s1.findOrder(numCourses, prerequisites);

    return 0;
}