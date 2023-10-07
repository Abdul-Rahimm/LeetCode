#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int lo=0,   hi=nums.size()-1;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        while(lo<hi){
            int total = sorted[lo] + sorted[hi];
            if(total == target)
                break;
            else if(total < target)
                lo++;
            else   
                hi--;
        }
    vector<int> ans;

    auto found = find(nums.begin(),nums.end(),sorted[lo]);
    int index_lo = distance(nums.begin(),found);
    ans.push_back(index_lo);
    nums.erase(nums.begin() + index_lo);

    found = find(nums.begin(),nums.end(),sorted[hi]);
    int index_hi = distance(nums.begin(),found);
    if(index_lo <= index_hi)     index_hi += 1;
    ans.push_back(index_hi);

    sort(ans.begin(),ans.end());
    return ans;


}
int main(){
    vector<int> nums{5,4,3,2,1};

    nums = twoSum(nums,8);
    for(int i:nums)
        cout << i <<" ";

}