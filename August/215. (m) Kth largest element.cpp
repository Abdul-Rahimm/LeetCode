#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int findKthLargest(vector<int>& nums, int k) {
    //one approach is sort the array in descending order
    //and return nums[k-1]

    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for(int i:nums){
        pq.push(i);

        if(pq.size() > k)
            pq.pop();
    }

    return pq.top();
}
int main(){
    vi nums{3,2,1,5,6,4};
    cout << findKthLargest(nums,2) << endl;

    vi nums2{3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(nums2,4) << endl;
      
  }