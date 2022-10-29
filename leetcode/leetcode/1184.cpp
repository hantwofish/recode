#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int resut = INT32_MAX;
        int frontIdex = start;
        int temp =0;
        while( frontIdex != destination){
            cout << "frontIdex= " << frontIdex << endl;
            temp += distance[frontIdex];
            
            if(++frontIdex  >= distance.size()){
                frontIdex = frontIdex - distance.size();
            }
            
        }
        resut = resut < temp ? resut : temp;

        int beheindIndex =start;
        temp =0;
        while(beheindIndex != destination){
            if(--beheindIndex  < 0){
                cout << "beheindIndex= " << beheindIndex << endl;
                beheindIndex = distance.size()- 1;
                
            }
            // beheindIndex--;
            temp += distance[beheindIndex];
        }
        resut = resut < temp ? resut : temp;

        return resut;

    }
};

int main()
{
    Solution s1;
    vector<int>  distance = {1,2,3,4};
    int start = 0, destination = 3;
    int resu = s1.distanceBetweenBusStops(distance, start, destination);
    cout << "main resu= " << resu << endl;
    return 0; 
}