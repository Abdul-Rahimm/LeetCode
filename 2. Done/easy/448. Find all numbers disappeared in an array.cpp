#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mapi;

void print(vi nums){
    for(int i:nums)
        cout << i << " ";
    cout << endl;
}
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vi pos(nums.size(),0);
    vi ans;
    for(int i:nums)
        pos[i-1]++;

    for(int i = 1; i <= nums.size() ; i++)
        if(pos[i-1] == 0)
            ans.push_back(i);

    return ans;
}
int main(){
    vi nums{4,3,2,7,8,2,3,1};
    vi ans = findDisappearedNumbers(nums);
    print(ans);

    vi nums1{1,1};
    ans = findDisappearedNumbers(nums1);
    print(ans);


}