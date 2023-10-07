#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int size_array;
int dp[201][1001];  

int solve(int idx, int target, vector<int> &nums){
    if(dp[idx][target] != -1)
        return dp[idx][target];

    if(target == 0)
        return 1;
    if(target < 0)
        return 0;
    if(idx >= size_array)
        return 0;

    int take   = solve(0,target-nums[i],nums);
    int reject = solve(idx+1,target,nums);


    return dp[idx][target] = take + reject;
}
int combinationSum4(vector<int>& nums, int target) {
    size_array = nums.size();
    memset(dp,-1,sizeof(dp));
    
    return solve(0,target,nums);
}
int main(){
    
}

