// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n-1);
        vector<int> answ(n-1);
        
        for(int i = 0 ; i < n-1 ;i++)
            diff[i] = nums[i+1] - nums[i];
        
        
        for(int x = 0; x < n-1 ; x++){
            int i = x;
            int ans = 0;
            int j = i;
            
            while(i < n-1 || j >= 0){
                if(j >= 0 && j != i)
                    ans += diff[j];
                
                ans += ans + diff[i];
                
                i++;
                j--;
            }
            
            answ[x] = ans;
        }
        return answ;
    }

void print(vi ans){
    for(int i: ans)
        cout << i << " ";
}
int main(){
    vector<int> nums{1,4,6,8,10};

    vector<int> ans = getSumAbsoluteDifferences(nums);
    print(ans);


}