#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
unordered_map<int,int> memo;

 int tribonacci(int n) {
        if(memo.count(n) > 0)   return memo[n];
        if(n <= 1)  return n;
        if(n == 2)  return 1;
        
        memo[n] =  tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return memo[n];
    }

int main(){
    cout << tribonacci(4) << endl;
    cout << tribonacci(25) << endl;
    

}