class Solution {
public:
    int mod = 1e9 + 7;
    int rev(int x){
        int ans = 0;
        
        while(x > 0){
            ans += x%10;
            x /= 10;
            
            if(x > 0)
                ans *= 10;
        }   
        
        return ans;
    }
    
    // nums[i] - rev(nums[i])  == nums[j] - rev(nums[j])
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
       for(int i = 0; i < n ; i++)
            nums[i] = nums[i] - rev(nums[i]);
        
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(int i: nums){
            mp[i]++;
            ans = (ans + mp[i] - 1) % mod;
        }
        
        
        return ans;
    }
};