#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef priority_queue<int, vi ,greater<int>> pq;//min heap

void print(vi nums){
    for(int i:nums)
        cout << i << " ";
    cout << endl;
}
int minimumOperations(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ptr = 0,score = 0;
    
    while(accumulate(nums.begin(),nums.end(),0) != 0){
        while(nums[ptr] == 0){
            ptr++;
        }

        int num = nums[ptr];
        transform(nums.begin()+ptr,nums.end(),nums.begin()+ptr, [num](int x){return x-num;});
        score++;
        print(nums);
    }

    return score;
}
int main(){
    vi nums{1,5,0,3,5};
    cout << minimumOperations(nums) << endl;

    vi nums2{0};
    cout << minimumOperations(nums2) << endl;
  
  }
  