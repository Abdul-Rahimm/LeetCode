#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
bool canCross_1(vector<int>& stones) {
    int step = 0;

    for(int i = 0 ; i < stones.size()-1 ; i++){
        int diff = stones[i+1] - stones[i];
        if(diff == step+1)
            step++;
        else if(diff == step)
            step = step;
        else if(diff < step && step >= 1)
            step--;
        else if(diff > step + 1)
            return false;
    }

    return true;
}

int n;
unordered_map<int,int> mp;  //<stone, index>
int t[2001][2001];

bool solve(vi &stones, int csi, int pj){
    if(csi == n-1)
        return true;
    if(t[csi][pj] != -1)
        return t[csi][pj];

    bool result = false;

    for(int nextjump = pj-1 ; nextjump <= pj+1 ; nextjump++){
        
        if(nextjump > 0){
            int nextstone = stones[csi] + nextjump;
                
            if(mp.find(nextstone) != mp.end()){
                //stone found
                result |= solve(stones,mp[nextstone],nextjump);
            }
        }
    }
    
    return t[csi][pj] = result;
}
bool canCross(vector<int>& stones) {
    n = stones.size();
    memset(t,-1,sizeof(t));

    if(stones[1] != 1)
        return false;

    for(int i = 0 ; i < n ; i++)
        mp[stones[i]] = i;

    return solve(stones ,0 , 0);
}
int main(){
    vi nums{0,1,3,5,6,8,12,17};
    cout << canCross(nums) << endl;
    
}

