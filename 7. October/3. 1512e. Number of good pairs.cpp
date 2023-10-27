class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int total = 0;
        
        for(int &i:nums)
            mp[i]++;
            
        for(auto &pair :mp){
            int freq = pair.second;
            
            total += (freq*(freq-1))/2;
        }
        
        return total;
    }   
};