 #include<bits/stdc++.h>
#include<algorithm>
using namespace std;
set<int,greater<int>> s;
int removeDuplicates(vector<int>& nums) {
    int i = 0 , len =  nums.size() , ret = nums.size();
    int smallest = INT_MIN;

    for(int j = 0 ; j < len; j++){
        if(nums[j] == smallest){
            nums.push_back(nums[j]);
            s.insert(j);
            i++;
        }
        else{
            smallest = nums[j];
        }
    }

    for(int pos : s){
        nums.erase(nums.begin() + pos);
    }

    for(int i : nums){
        cout << i << " ";
    }
    cout << endl << endl;
    return ret-i;
}
int removeDuplicates__0_ms(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[k])
            {
                nums[k+1]=nums[i];
                k++;
            }
        }
        return k+1;
    }
int main(){
    vector<int> nums{0,0,1,1,1,2,2,3,3,4,4,5,5,5};
    cout << removeDuplicates(nums) << endl;
}