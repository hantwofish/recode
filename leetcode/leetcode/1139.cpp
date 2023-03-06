#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int maxWidth = min(grid.size(), grid[0].size());
        cout << "maxWidth= " << maxWidth << endl;
        int resu = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                for(int width = 1 ; width <= maxWidth; width++){

                    cout << "i = " << i << " j = " << j << " width= " << width << endl;
                    if(isVaile(grid, i,j ,width)){
                        resu = max(resu, width*width);
                    }
                    
                }
            }
        }

        return resu;
    }
    bool isVaile(vector<vector<int>>& grid, int row, int col, int width)
    {
        int endRow = row + width -1;
        int endcol = col + width - 1;

        if(endcol >= grid[0].size()){
            return false;
        }
        if(endRow >= grid.size()){
            return false;
        }
        cout << "endRow= " << endRow << " endCol= " << endcol << " width= " <<  width <<  endl;
        for(int j = col; j <= endcol; j++){

            if(grid[row][j] ==0){
                return false;
            }
            if(grid[endRow][j] == 0){
                return false;
            }
        }
        for(int i = row; i <= endRow; i++){

            if(grid[i][col] ==0){
                return false;
            }
            if(grid[i][endcol] == 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> grid = {{1,1,0,0}};
    int resu = s1.largest1BorderedSquare(grid);
    cout << "resu= " << resu << endl;
    return 0;
}