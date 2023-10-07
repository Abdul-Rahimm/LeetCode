 #include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for(int j = 0 ; j < nums.size() ; j++){
        if(nums[j] != val){
            swap(nums[i],nums[j]);
            i++;
        }
    }
    return i;
}
int removeElement_0ms(vector<int>& nums, int val) {
        std::vector<int>ans;
        for(auto i : nums)
        {
            if(i != val)
            {
                ans.push_back(i);
            }
        }
        nums = ans;

        return nums.size();
    }


int main(){
    vector<int> array{0,1,2,2,3,0,4,2};
    cout << removeElement(array,2) << endl;


}   