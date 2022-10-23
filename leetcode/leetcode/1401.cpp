#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        return true;
    }
};

int main()
{
    Solution s1;
    int radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    bool resu = s1.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    if(resu){
        cout<< "resu= True" << endl;
    }else{
        cout<< "resu= False " << endl;
    }

}