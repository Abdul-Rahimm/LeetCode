#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , m = nums1.size();
        int j = 0 , n = nums2.size();
        int k = 0;
        
       
        
        
        n = n+m;
        if(n % 2)
            return nums[n/2];
        else
            return (nums[n/2] + nums[(n/2) - 1])/2.0;
    }
};

//         priority_queue<int> pq;
//         for(int i : nums1)
//             pq.push(i);
        
//         for(int i : nums2)
//             pq.push(i);
        
//         int n = pq.size();
//         vector<int> nums;

// while(!pq.empty()){
//             nums.push_back(pq.top());
//             pq.pop();
//         }

// while(i < m && j < n){
//             if(nums1[i] <= nums2[j]){
//                 nums[k++] = nums1[i++];
//             }
//             else
//                 nums[k++] = nums2[j++];
//         }
        
//         while(i < m)
//             nums[k++] = nums1[i++];
//         while(j < n)
//             nums[k++] = nums2[j++];


















