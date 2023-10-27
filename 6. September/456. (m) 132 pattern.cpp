// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef array<int,2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;
 
 vector<int> gnums;
    
bool is132(int& high,int& low, int idx){
    for(int i = idx+1 ; i < gnums.size() ; i++){
        if(gnums[i] < high && gnums[i] > low)
            return true;
    }
    
    return false;
}
bool find132pattern(vector<int>& nums) {
        gnums = nums;
        bool rise = false;
        int low = INT_MAX;
        
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            bool decline = false;
            
            if(nums[i] > nums[i+1] && is132(nums[i],low,i)){
                decline = true;
            }
            
            if(nums[i] < nums[i+1]){
                rise = true;
                low = min(low,nums[i]);
            }
            
            
            if(rise && decline)
                return true;
        }
        
    return false;
    }

bool find132pattern(vector<int>& nums){
    int n = nums.size();

    int num3 = INT_MIN;
    stack<int> s;

    for(int i = n-1 ; i >= 0 ; i--){
        if(nums[i] < num3)
            return true;

        while(!s.empty() && s.top() < nums[i]){
            num3 = s.top();
            st.pop();
        }

        s.push(nums[i]);
    }

    return false;
}

int main(){



}