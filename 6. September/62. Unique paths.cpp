#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int rows,cols;
int dp[101][101];

int solve(int i,int j){
    if(i == rows-1 && j == cols-1)
        return 1;
    if(i >= rows || i < 0 || j >= cols || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = solve(i,j+1);
    int down = solve(i+1,j);

    return dp[i][j] = right+down;
}
int uniquePaths(int m, int n) {
    rows = m;
    cols = n;

    memset(dp,-1,sizeof(dp));
    return solve(0,0);
}

int main(){
    
}

