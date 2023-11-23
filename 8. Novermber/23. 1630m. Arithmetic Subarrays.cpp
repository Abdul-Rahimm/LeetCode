class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for(int i = 0 ; i < l.size() ; i++){
            int left = l[i];
            int right = r[i];
            
            vector<int> array;
            for(int j = left; j <= right ; j++)
                array.push_back(nums[j]);
            
            sort(begin(array),end(array));
            
            int diff = array[1] - array[0];
            bool status = true;
            
            for(int j = 2; j < array.size(); j++){
                if(array[j] - array[j-1] != diff){
                    ans.push_back(false);
                    status = false;
                    break;
                }
            }
            
            if(status)
                ans.push_back(true);
        }
        
        return ans;
    }
};