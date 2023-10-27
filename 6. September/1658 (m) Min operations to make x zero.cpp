#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
unordered_map<int,int> mp;

int minOperations(vector<int>& nums, int x) {        
    int n    = nums.size();
    int sum  = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    
    for(int i = 0; i<n; i++) {
        sum += nums[i];
        mp[sum] = i;
    }

    if(sum < x)
        return -1;

    int restSum  = sum-x;
    int longest  = INT_MIN;
    sum = 0;

    for(int i = 0; i<n; i++) {
        sum += nums[i];
        if(mp.count(sum-restSum)) {
            longest = max(longest, i-mp[sum-restSum]);
        }
    }
    
    return longest==INT_MIN?-1:n-longest;
}

int main(){
    vector<int> nums{3,2,1,1,1,1,1,3,1};
    cout << minOperations(nums,10) << endl;

}