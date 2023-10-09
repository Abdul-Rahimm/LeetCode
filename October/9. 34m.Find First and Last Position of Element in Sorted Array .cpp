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
    int left_most = -1;
    int num_mid;
    int l = 0 , r = n-1 ;
    

    while(l <= r){
        int mid = (l + (r-l))/2;
        num_mid = nums[mid];
        
        if(num_mid == target){
            left_most= mid;
            r = mid-1;
        }
        else if(num_mid > target)
            r = mid-1;
        else   
            l = mid+1;
    }

    return left_most;
}
int search_right_most(vi &nums, int target){
    int r_most = -1;
    int num_mid;
    int l = 0 , r = n-1 ;

    while(l <= r){
        int mid = (l + (r-l))/2;
        num_mid = nums[mid];

        if(num_mid == target){
            r_most= mid;
            l = mid+1;
        }
        else if(num_mid > target)
            r = mid-1;
        else   
            l = mid+1;
    }

    return r_most;
}
vector<int> searchRange(vector<int>& nums, int target) {
    n = nums.size();

    int left_most  = search_left_most(nums,target);
    int right_most = search_right_most(nums,target);

    return {left_most,right_most};
}

int main(){
    vi nums{5,7,7,8,8,10};
    vi ans = searchRange(nums,8);
    print(ans);


}