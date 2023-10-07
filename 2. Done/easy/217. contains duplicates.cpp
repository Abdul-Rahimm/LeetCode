#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    int max = INT_MIN;
    for(int i: nums)
        if(i > max)
            max = i;

    vector<int> pos(max,0);

    for(int i :nums){
        pos[i] = pos[i] + 1;
        int x = pos[i];
        if(x > 1)
            return true;
        
    }       

    return false;
}

int main(){
    vector<int> nums{1,2,3,1};
    cout << containsDuplicate(nums) << endl;
 }