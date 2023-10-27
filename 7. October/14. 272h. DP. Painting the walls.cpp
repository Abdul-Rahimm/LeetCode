// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int dp[501][501];

int solve(vi &cost, vi &time, int idx, int rem){

    if(rem <= 0)
        return 0;
    if(idx >= cost.size())
        return 1e9;
    if(dp[idx][rem] != -1)
        return dp[idx][rem];

    int paint_wall = cost[idx] + solve(cost, time, idx+1, rem-1-time[idx]);
    int not_paint  = solve(cost, time, idx+1, rem);

    return dp[idx][rem] = min(paint_wall,not_paint);
} 

int paintWalls(vector<int>& cost, vector<int>& time) {
    
    memset(dp,-1,sizeof(dp));
    return solve(cost,time,0,cost.size());
}

int main(){
    vi cost{1,2,3,2};
    vi time{1,2,3,2};

    cout << paintWalls(cost,time) << endl;


}