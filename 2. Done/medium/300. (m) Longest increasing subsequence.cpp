#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void print(vector<vector<int>> &mat){
    for(auto row:mat){
        for(int i:row)
            cout << i << " ";
    cout << endl;
    }
}
int findLongestChain_101(vector<vector<int>>& pairs) {
    sort(pairs.begin(),pairs.end());
    
    int j,i,ret,ans=0;
    
    for(int z = 0 ; z < pairs.size() - 1 ; z++){
    ret = 1;
    i = z;
    j = i+1;
    cout << endl;

    while(j < pairs.size()-1){
        j = i+1;
        while(pairs[i][1] >= pairs[j][0] && j < pairs.size()-1)
            j++;

        cout << pairs[i][1] << " " << pairs[j][0] << endl;

        if(pairs[i][1] < pairs[j][0])  
            ret++;

        ans = max(ret,ans);
        i = j;

    }
}
    return ans;
}

int n;
int dp[1001][1001];
int solve(vector<vector<int>>> &nums, int i, int prev){
    if(i >= n)  //out of bound
        return 0;

    if(dp[i][prev] != -1 && prev != -1) //index always pos
        return dp[i][prev];

    //take
    int take = 0;
    if(prev == -1 || nums[i][0] > nums[prev][1])
        take = 1 + solve(nums,i+1,i);

    //skip
    int skip = 0;
        skip = solve(nums,i+1,prev);

    if(prev != -1)
        dp[i][prev] = max(take,skip)

    return max(take,skip);
    
}
int findLongestChain(vector<vector<int>>& pairs) {
    n = pairs.size();
    memset(dp,-1,sizepf(dp));

    sort(pairs.begin(),pairs.end());
    return solve(pairs, 0,-1);
}

int main(){
    

}

