#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int len = nums.size();
    return (nums[len-1]-1)*(nums[len-2]-1);
}

int main(){
    vector<int> nums{3,7};
    cout << maxProduct(nums) << endl;


}