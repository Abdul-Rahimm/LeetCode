// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++) {
            
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            
            int in_range  = j - i;
            int out_range = n - in_range;
            
            result = min(result, out_range);
            
        }
        
        return result;
    }


int main(){



}

