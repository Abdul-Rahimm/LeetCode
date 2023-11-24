// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int maxCoins(vector<int>& piles) {
    priority_queue<int, vector<int>> pq;
    int count = piles.size() / 3, ans = 0;

    for(int i: piles)
        pq.push(i);

    while(count--){
        pq.pop();
        ans += pq.top();
        pq.pop();
    }
    
    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<int> nums(t);

    for(int i = 0 ; i < t ; i++)
        cin>>nums[i];

    cout << maxCoins(nums) << endl;


}