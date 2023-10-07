#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
unordered_map<int,int> memo;
int climbStairs(int n) {
    if(memo.count(n) > 0)   return memo[n];
    if(n == 0)  return 1;
    if(n < 0)   return 0;

    memo[n] = climbStairs(n-1)+climbStairs(n-2);
    return memo[n];
    
}

int main(){
    int t,n;

    cout << "t: ";
    cin >> t;
    while(t--){
        cout << "enter n: ";
        cin >> n;
        cout << climbStairs(n) << endl;
    }
    


}