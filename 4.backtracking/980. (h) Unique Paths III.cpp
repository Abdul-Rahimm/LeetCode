#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vii directions{{1,0},{-1,0},{0,1},{0,-1}};
int m, n, nonobstacle , result = 0;

void backtrack(vii &grid, int count, int i, int j){
    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
        return;

    if(grid[i][j] == 2){
        if(count == nonobstacle)
            result++;
        
        return;
    }

    grid[i][j] = -1;

    //backtracking logic
    for(vector<int> dir:directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        backtrack(grid,count+1,new_i,new_j);
    }

    grid[i][j] = 0;

}
int uniquePathsIII(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    nonobstacle = 0;
    result = 0;

    int start_x,start_y;

    for(int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < 0 ; j++){
            if(grid[i][j] == 0)
                nonobstacle++;

            if(grid[i][j] == 1){
                start_x = i;
                start_y = j;
            }
        }
    }
    
    nonobstacle += 1;
    int count = 0;          //itne non obtacles cover krlie

    backtrack(grid, count , start_x, start_y);

    return result;
}

int main(){
    vii grid{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(grid) << endl;
    
    // vii grid1{{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    // cout << uniquePathsIII(grid1) << endl;

    // vii grid2{{0,1},{2,0}};
    // cout << uniquePathsIII(grid2) << endl;


   
}