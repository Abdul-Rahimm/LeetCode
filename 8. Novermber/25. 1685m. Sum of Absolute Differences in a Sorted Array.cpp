// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n-1);
        vector<int> answ(n-1);
        
        for(int i = 0 ; i < n-1 ;i++)
            diff[i] = nums[i+1] - nums[i];
        
        
        for(int x = 0; x < n-1 ; x++){
            int i = x;
            int ans = 0;
            int j = i;
            
            while(i < n-1 || j >= 0){
                if(j >= 0 && j != i)
                    ans += diff[j];
                
                ans += ans + diff[i];
                
                i++;
                j--;
            }
            
            answ[x] = ans;
        }
        return answ;
    }
 vector<int> getSumAbsoluteDifferences_MIK(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        
        for(int i = 1; i<n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            int leftSum   = prefixSum[i] - nums[i];
            int rightSum  = prefixSum[n-1] - prefixSum[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
        }
        
        return result;
        
    }
void print(vi ans){
    for(int i: ans)
        cout << i << " ";
}
int main(){
    vector<int> nums{1,4,6,8,10};

    vector<int> ans = getSumAbsoluteDifferences(nums);
    print(ans);


}