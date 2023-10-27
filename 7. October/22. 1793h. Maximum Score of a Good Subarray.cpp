// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int maximumScore(vector<int>& nums, int k) {

    int n = nums.size();
    int i = k;
    int j = k;
    int currmin = nums[i];
    int result  = nums[i];

    while(i > 0 || j < n-1){
        int left =  (i > 0)   ? nums[i-1] : 0;
        int right = (j < n-1) ? nums[j+1] : 0;

        if(left > right){
            i--;
            currmin = min(currmin, nums[i]);
        }
        else{
            j++;
            currmin = min(currmin, nums[j]);
        }

        result = max(result, currmin * (j-i+1));
    }

    return result;
}

int main(){
                   //0 1 2 3 4 5
    vector<int> nums{3,7,4};
    cout << maximumScore(nums,1) << endl;


}