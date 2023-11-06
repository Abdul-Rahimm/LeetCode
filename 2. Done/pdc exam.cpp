// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int solve(vi nums,int start,int end){
    
    if(end-start > 1){
        int mid = start + (end-start)/2;
        int a = solve(nums,start,mid);
        int b = solve(nums,mid+1,end);

        return min(a,b);
    }

    return min(nums[start],nums[end]);

}

int main(){
    int t;
    cin >> t;
    vector<int> nums(t);

    for(int i = 0 ; i < t ; i++){
        cin >> nums[i];
    }

    int ans = solve(nums,0,t-1);

    cout << ans;

}