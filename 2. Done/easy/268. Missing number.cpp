#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void print(vector<int> nums){
    cout << endl;
    for(int i: nums) 
        cout << i << " ";
    cout << endl;
}
int missingNumber1(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int len = nums.size();
    int left = 0 , right = len;

    //print(nums);
    while(left <= right){
        if(nums[left] != left)
            return left;
        if(nums[right-1] != right)
            return right;
        
        left++;right--;
    }

}
int missingNumber2(vector<int>& nums){
    map<int,int> mp;
    for(int i:nums)
        mp[i]++;

    for(int i = 0 ; i <= nums.size() ; i++){
        if(mp[i] == 0)
            return i;
    }
}
int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans=ans^nums[i];
        }
        for(int j=0; j<=nums.size(); j++){
            ans=ans^j;
        }
        return ans;
    }

int main(){
    vector<int> nums{0,1,2,5,4};
    cout << missingNumber(nums) << endl;

    
    

}