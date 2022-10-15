#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int city_number =passingFees.size();
        vector<vector<int>>way(city_number , vector<int>(city_number, 0));
        for(int i = 0 ; i < edges.size(); i++){
            way[edges[i][0]][edges[i][1]] = edges[i][2];
            way[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        vector<bool>te(city_number,0);
        visited = te;

        cost_value = passingFees[0];
        back_tracing(maxTime, way, passingFees , 0, city_number -1);
        return result;

        return 0;
    }
    void back_tracing(int maxTime, vector<vector<int>>&way, vector<int>&passFees, int Start_num , int End_num)
    {
        if(cost_time > maxTime){
            return;
        }
        if(visited[Start_num]){
            return;
        }
        if(Start_num >= End_num){
            //cout << "cost_time= " << cost_time << " cost_value= " << cost_value << endl;
            result = min(result, cost_value);
        }
        
        visited[Start_num] = true;
        for(int j = 0 ; j < way.size(); j++){
            if( way[Start_num][j] == 0 ){
                continue;
            }
            cost_value += passFees[j];
            cost_time += way[Start_num][j];
            back_tracing(maxTime, way, passFees, j , End_num);
            cost_value -= passFees[j];
            cost_time -= way[Start_num][j];
        }
        visited[Start_num] = false;
    }

    
private:
    int cost_time = 0;
    int cost_value = 0;
    int result = INT32_MAX;
    vector<bool>visited;
};

int main()
{
    int maxTime = 500;
    vector<vector<int>>edges = {{9,7,18},{26,3,12},{28,45,33},{47,10,27},{34,18,38},{32,13,39},{32,26,32},{12,0,2},{4,1,7},{5,3,2},{39,25,27},{45,10,34},{3,19,5},{25,32,23},{30,10,47},{37,2,31},{10,32,15},{23,14,19},{22,6,14},{45,39,38},{39,21,30},{42,17,42},{20,17,15},{24,0,27},{2,46,11},{2,24,13},{36,22,30},{2,1,31},{41,35,45},{4,19,20},{32,27,33},{38,46,1},{21,11,15},{33,41,2},{45,18,30},{8,33,50},{37,11,6},{25,17,42},{45,39,33},{7,4,49},{17,42,36},{36,16,9},{46,25,24},{43,4,6},{35,13,28},{1,28,1},{34,35,15},{38,1,15},{16,6,28},{13,0,42},{3,30,24},{43,27,35},{8,0,45},{27,20,47},{6,16,47},{0,34,35},{0,35,3},{40,11,24},{1,0,49},{44,20,32},{26,12,17},{3,2,25},{37,25,42},{27,1,15},{36,25,38},{24,47,33},{33,28,15},{25,43,37},{47,31,47},{29,10,50},{11,1,21},{29,3,48},{1,25,10},{48,17,16},{19,24,22},{30,7,2},{11,22,19},{20,42,41},{27,3,48},{17,0,34},{19,14,32},{49,2,20},{10,3,38},{0,49,13},{6,3,28},{42,23,6},{14,8,1},{35,16,3},{17,7,40},{18,7,49},{36,35,13},{14,40,45},{16,33,11},{31,22,33},{38,15,48},{15,14,25},{37,13,37},{44,32,7},{48,1,31},{33,12,20},{22,26,23},{4,10,11},{43,28,43},{19,8,14},{35,31,33},{28,27,19},{40,11,36},{36,43,28},{22,21,15}}
;
    vector<int> passingFees = {199,505,107,961,682,400,304,517,512,18,334,627,893,412,922,289,19,161,206,879,336,831,577,802,139,348,440,219,273,691,99,858,389,955,561,353,937,904,858,704,548,497,787,546,241,67,743,42,87,137};
    Solution s1;
    int resu = s1.minCost(maxTime, edges, passingFees);
    cout << "main resu= " << resu << endl;
    return 0;
}