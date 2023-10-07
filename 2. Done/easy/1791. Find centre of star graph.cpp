#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    unordered_map<int,int> mp;
    for(auto row: edges)
        for(int i:row){ 
            mp[i]++;

            if(mp[i] > 1)
                return i;
        }
    return 0;
}
int main(){
    
    
}

