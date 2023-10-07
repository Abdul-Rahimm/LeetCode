#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int n;
int t[100001];

bool solve(vi &nums,int i){
    if (i >= n)
        return true;

    bool result = false;

    if(t[i] != -1)
        return t[i];

    if(i+1 < n && nums[i] == nums[i+1])
        result |= solve(nums,i+2);
    
    

    if(i+2 < n && nums[i] == nums[i+1] && nums[i] == nums[i+2])
        result |= solve(nums,i+3);

    

    if(i+2 < n && nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2])
        result |= solve(nums,i+3);
    
    return t[i] = result;
}
bool validPartition(vector<int>& nums) {
    n = nums.size();

    memset(t, -1, sizeof(t));
    return solve(nums,0);
    
}
int main(){
    vi nums{4,4,4,5,6};
    cout << validPartition(nums) << endl;

    vi nums2{1,1,1,2};
    cout << validPartition(nums2) << endl;
  
  
  
}