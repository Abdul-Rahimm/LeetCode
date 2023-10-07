#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<vector<int>> vii;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int,stack<int>> mp;
    vii ans;

    for(int i = 0 ; i < groupSizes.size() ; i++)
        mp[groupSizes[i]].push(i);

    for(auto &pair : mp){
        int num = pair.first;
        stack<int> stk = pair.second;
        int size = stk.size();
        vector<int> array;

        for(int j = 0 ; j < size/num ; j++){
            for(int i = 0 ; i < num ; i++){
                array.push_back(stk.top());
                stk.pop();
            }

            pair.second = stk;
            ans.push_back(array);
            array.clear();
        }
    }

    return ans;
}

void print(vii nums){
    for(auto row:nums){
        for(int i: row)
            cout << i << " ";
    cout << endl;
    }
}
int main(){
    vector<int> nums{3,3,3,3,3,1,3};
    vii ans = groupThePeople(nums);
    print(ans);
    

}