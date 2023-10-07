#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> mp;
    vector<int> ans;

    for(int i:nums)
        mp[i]++;

    priority_queue<pair<int,int>> pq;

    for(auto mp_pair:mp){
        pair<int,int> pr;
        pr.first = mp_pair.second;
        pr.second = mp_pair.first;
        pq.push(pr);
    }

    for(int i = 0 ; i < k ; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}
void print(vector<int> ans){
    for(int i:ans)
        cout << i << " ";
}
int main(){
    vector<int> nums{1};
    vector<int> ans = topKFrequent(nums,1);
    print(ans);
}

