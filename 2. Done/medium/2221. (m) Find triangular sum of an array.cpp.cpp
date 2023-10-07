#include<bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int rows = nums.size(),total ; //5
    vector<vector<int>> sums(rows);
    if(rows == 1)  return nums[0];

    for(int num : nums)
        sums[0].push_back(num);

    for(int i = 1 ; i < rows ; i++){

        for(int j = 0 ; j < rows - i ; j++){
            total = sums[i-1][j] + sums[i-1][j+1];
            if(total >= 10)  total-= 10;
            sums[i].push_back(total);
        }  

    }   
    return sums[rows-1][0];

}
int short_good(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }

int main(){
    vector<int> nums{1,2,3,4};

    cout << triangularSum(nums) << endl;
    // triangularSum(nums);
}