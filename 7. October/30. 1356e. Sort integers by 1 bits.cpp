// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pr;
 
vector<int> sortByBits(vector<int>& arr) {
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    for(int i:arr){
        pq.push({__builtin_popcount(i),i});
    }

    vector<int> ans;
    while(!pq.empty()){
        int num = pq.top().second;
        ans.push_back(num);
        pq.pop();
    }

    return ans;
}

int main(){
    vi nums{1024,512,256,128,64,32,16,8,4,2,1};
    vi ans = sortByBits(nums);
    print(ans);


}