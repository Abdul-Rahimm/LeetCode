#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
void print(vi nums){
    for(int i:nums)
        cout << i << " ";
    cout << endl;
}
int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();

    for(int i : nums){
        if(i >= 1 && i < nums.size())
            nums[i-1] = i;
    } 

    //print(nums);
    for(int i = 0 ; i < len ; i++){
        if(nums[i] != i+1)
            return i+1;
    }

    return 0;
    
}
int correct_iffirstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
int main(){
    vi nums{1,2,0};
    cout << firstMissingPositive(nums) << endl;

    vi nums1{3,4,-1,1};
    cout << firstMissingPositive(nums1) << endl;

    vi nums2{7,8,9,10};
    cout << firstMissingPositive(nums2) << endl;

    
}