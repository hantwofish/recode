class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses);
        vector<set<int>> pre(numCourses);
        for(auto &v:prerequisites){
            int v1=v[0],v2=v[1];
            adj[v1].push_back(v2);
            degree[v2]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(auto next:adj[course]){
                degree[next]--;
                pre[next].insert(pre[course].begin(),pre[course].end());
                pre[next].insert(course);
                if(degree[next]==0)
                    q.push(next);
            }
        }
        vector<bool>res;
       
        for(auto q:queries){
            if(pre[q[1]].find(q[0])!=pre[q[1]].end())
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }

};

作者：KarlHarris
链接：https://leetcode.cn/problems/course-schedule-iv/solution/jian-dan-yi-dong-de-tuo-bu-pai-xu-by-kar-7q6f/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。