#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n+1);
    for(int i = 0 ; i <= n ; i++){
        ans[i] = __builtin_popcount(i);
    }
    return ans;
}
void print(vector<int> ans){
    for(int i:ans)
        cout << i << " ";
}
int main(){
    vector<int> ans =  countBits(16);
    print(ans);
}

