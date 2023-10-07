#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pr;
typedef priority_queue<pr, vector<pr>, greater<pr>> pqq;//min heap

vector<int> maxSubsequence(vector<int>& nums, int k) {
    pqq pq;
    priority_queue<int, vi, greater<int>> indexes;
    
    int len = nums.size();
    vector<int> pos(len);

    int index = 0;
    for(int i : nums){
        pq.push({i,len-1-index});
        pos[len-1-index] = index;
        index++;

        if(pq.size() > k)
            pq.pop();
    }

    while(!pq.empty()){
        indexes.push(pq.top().second);
        pq.pop();
    }
    vi ans;
    while(!indexes.empty()){
       ans.push_back(nums[pos[indexes.top()]]);
       indexes.pop();
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
void print(vi nums){
    for(int i: nums){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
    vi nums{2,1,3,3};
    vi ans = maxSubsequence(nums,2);
    print(ans);

    vi nums2{-1,-2,3,4};
    ans = maxSubsequence(nums2,3);
    print(ans);

    vi nums3{3,4,3,3};
    ans = maxSubsequence(nums3,2);
    print(ans);

}

