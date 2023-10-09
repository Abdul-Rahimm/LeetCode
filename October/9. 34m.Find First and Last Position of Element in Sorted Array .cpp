// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
void print(vi nums){
    for(int i : nums)
        cout << i << " ";
}

int n;
int search_left_most(vi &nums, int target){
    int l = 0, r = n-1;

    int left_most = -1;

    while(l <= r){
        int mid = l + (r-l)/2;
        int num_mid = nums[mid];

        if(num_mid == target){
            left_most = mid;
            r = mid-1;
        }
        else if(num_mid < target)
            l = mid+1;
        else    
            r = mid-1;

    }

    return left_most;
}
int search_right_most(vi &nums, int target){
    int l = 0, r = n-1;

    int right_most = -1;

    while(l <= r){
        int mid = l + (r-l)/2;
        int num_mid = nums[mid];

        if(num_mid == target){
            right_most = mid;
            l = mid+1;
        }
        else if(num_mid < target)
            l = mid+1;
        else    
            r = mid-1;

    }

    return right_most;
}
vector<int> searchRange(vector<int>& nums, int target) {
    n = nums.size();

    int left_most  = search_left_most(nums,target);
    int right_most = search_right_most(nums,target);

    return {left_most,right_most};
    // return {left_most,0};
}

int main(){
    vi nums{5,7,7,8,8,10};
    vi ans = searchRange(nums,8);
    print(ans);


}