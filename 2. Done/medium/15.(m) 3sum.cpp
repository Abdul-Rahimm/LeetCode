#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
map<vector<int>,int> mp;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> temp;
    vector<vector<int>> ret;

    int len = nums.size();

    for(int i = 0 ; i < len ; i++){
        int first = i+1, last = len - 1;  //ptrs
        while(first < last){

            if(first == i)  first++;
            if(last == i)   last--;

            int sum = nums[first] + nums[i] + nums[last];
            if(sum == 0){
                temp.push_back(nums[first]);
                temp.push_back(nums[i]);
                temp.push_back(nums[last]);
                
                //sort(temp.begin(),temp.end());
                mp[temp]++;

                if(mp[temp] == 1)
                    ret.push_back(temp);

                temp.clear();
                last--;
                first++;
            }

            if(sum > 0) last--;
            if(sum < 0) first++;
        }
    }
    
    return ret;
}

void print(vector<vector<int>> nums){
    for(auto row:nums){
        for(int i:row)
            cout << i << " ";
    cout << endl;
    }
}
int main(){
    vector<int> nums{0,0,0,0};
    vector<vector<int>> ans = threeSum(nums);
    print(ans);
    
}