#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void print(vector<vector<int>> &mat){
    for(auto row:mat){
        for(int i:row)
            cout << i << " ";
    cout << endl;
    }
}
int findLongestChain_101(vector<vector<int>>& pairs) {
    sort(pairs.begin(),pairs.end());
    
    int j,i,ret,ans=0;
    
    for(int z = 0 ; z < pairs.size() - 1 ; z++){
    ret = 1;
    i = z;
    j = i+1;
    cout << endl;

    while(j < pairs.size()-1){
        j = i+1;
        while(pairs[i][1] >= pairs[j][0] && j < pairs.size()-1)
            j++;

        cout << pairs[i][1] << " " << pairs[j][0] << endl;

        if(pairs[i][1] < pairs[j][0])  
            ret++;

        ans = max(ret,ans);
        i = j;

    }
}
    return ans;
}

int main(){
    vector<vector<int>> mat{{7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3}};
    cout << findLongestChain(mat) << endl;
    
}

