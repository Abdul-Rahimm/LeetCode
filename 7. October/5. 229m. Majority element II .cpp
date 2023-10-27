class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<int> st;
        vector<int> ans;
        int n = nums.size();
        
        for(int &i : nums){
            mp[i]++;
            
            if(mp[i] > n/3)
                st.insert(i);
        }
        
        for(int i : st)
            ans.push_back(i);
        
        return ans;
    }
};