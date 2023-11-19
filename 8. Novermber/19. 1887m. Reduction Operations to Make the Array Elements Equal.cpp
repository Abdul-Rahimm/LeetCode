// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int reductionOperations(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
            
        sort(nums.begin(),nums.end());
        
        int smallest = nums[0];
        int ans = 0;
        int count = 0;
        int j = 1;

        while(nums[j] == smallest)
            j++;

        for(int i = j; i < nums.size(); i++){
            if(nums[i-1] != nums[i])
                count++;

            ans += count;
        }
        
        return ans;
    }

int main(){
    int t;
    cin >> t;
    vector<int> nums(t);

    for(int i = 0 ; i < t ; i++)
        cin >> nums[i];

    cout << reductionOperations(nums) << endl;


}