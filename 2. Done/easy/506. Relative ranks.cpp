#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int,int>> pq;   //score,index
    int len = score.size();
    vector<string> ans(len);
    int index = 0;

    for(int i:score){
        pq.push({i,index});
        index++;
    }

    ans[pq.top().second] = "Gold Medal";
    pq.pop();
    if(!pq.empty()){
        ans[pq.top().second] = "Silver Medal";
        pq.pop();
    }
    if(!pq.empty()){
        ans[pq.top().second] = "Bronze Medal";
        pq.pop();
    }

    int pos = 4;
    while(!pq.empty()){
        ans[pq.top().second] = to_string(pos);  pos++;
        pq.pop();
    }

    return ans;
}
void print(vector<string> ans){
    for(string i : ans)
        cout << i << " ";
    cout << endl;
}

int main(){
    vi nums{5,4,3,2,1};
    vector<string> ans = findRelativeRanks(nums);
    print(ans);

    vi nums2{10,3,8,9,4};
    ans = findRelativeRanks(nums2);
    print(ans);

}

