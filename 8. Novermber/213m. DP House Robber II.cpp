#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
int dp[101][101];
int solve(int i, int n){
    if(i >= n)
        return 0;
    if(dp[i][n] != -1)
        return dp[i][n];
    
    int take;
    if(i == 0 && n > 1)
        take = nums[i] + solve(i+2,n-1);
    else
        take = nums[i] + solve(i+2,n);
    
    int ntake = solve(i+1,n);
    
    return dp[i][n] = max(take,ntake);
}

int rob(vector<int>& arr) {
    memset(dp,-1,sizeof(dp));
    nums = arr;
    int n = arr.size();
    
    if(n == 1)
        return arr[0];
    
    return solve(0,n);
    
}

int main(){
    int n;
    cin >> n;

    vector<int> array(n);
    for(int i = 0 ; i < n ; i++)
        cin >> array[i];

    cout << rob(array) << endl;
}