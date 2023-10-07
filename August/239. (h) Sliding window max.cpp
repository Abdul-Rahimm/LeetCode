#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pq;//max heap

void print(vi ans){
    for(int i:ans)
        cout << i << " ";
    cout << endl;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deq; //deq will have the indexes
    int n = nums.size();

    for(int i = 0 ; i < n ; i++){

        //step1: make space for nums[i]
        while(!deq.empty() && deq.front() <= i-k ){
            deq.pop_front();
        }

        //step2: 
        while(!deq.empty() && nums[i] > nums[deq.back()]){
            deq.pop_back();
        }

        //step3: push index into deq
        deq.push_back(i);

        //step4: if i>k-1 -- window start
        if(i >= k-1){
            ans.push_back(nums[deq.front()]);
        }
    }
    return ans;
}
int main(){
    vi nums{1,3,-1,-3,5,3,6,7};
    vi ans = maxSlidingWindow(nums,3);
    print(ans);

    vi nums2{1};
    ans = maxSlidingWindow(nums2,1);
    print(ans);
}