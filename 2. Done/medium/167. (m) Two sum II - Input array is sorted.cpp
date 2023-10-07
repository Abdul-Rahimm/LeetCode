#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
void print(vi nums){
    for(int i:nums)
        cout << i << " ";
    cout << endl;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    vi ret;
    int len = numbers.size();
    int left = 0, right = len -1;

    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            ret.push_back(left+1);
            ret.push_back(right+1);
            break;
        }
        else if(sum > target)
            right--;
        else    
            left++;
    }

    return ret;
}
int main(){
    vi nums{2,7,11,15};
    vi ans = twoSum(nums,9);
    print(ans);
    
    vi nums1{2,3,4};
    ans = twoSum(nums1,6);
    print(ans);
    
    vi nums2{-1,0};
    ans = twoSum(nums2,-1);
    print(ans);



    
}