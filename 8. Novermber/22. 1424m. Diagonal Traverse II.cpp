class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        
        for(int i = n-1 ; i >= 0 ; i--){
            int len = nums[i].size();
            
            for(int j = 0 ; j < len ; j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        for(auto pair: mp){
            vector<int> values = pair.second;
            
            for(int i : values)
                ans.push_back(i);
        }
        
        return ans;
    }
};