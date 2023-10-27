#include<bits/stdc++.h>
using namespace std;

string str;
int dp[1001][1001];
string solve(int i, int j){
        
        if(i >= j && str[i] != str[j])
            return "";
        if(i >= j && str[i] == str[j])
            return str[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(str[i] != str[j]){
            return dp[i][j] = solve(i+1,j);
            return dp[i][j] = solve(i,j-1);
        }
        else{
            return dp[i][j] = solve(i+1,j-1);
        }
        
        return "";       
}
string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        str = s;
        return solve(i,j);
    }

    
bool solve_mik(int i,int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i >= j)
        return true;
    
    if(str[i] == str[j])
        return dp[i][j] = solve(i+1,j-1);
    else
        return dp[i][j] = false;
} 
string longestPalindrome_mik(string s) {
        memset(dp,-1,sizeof(dp));
        
        int n = s.length();
        int sp     = -1;
        int maxlen =  0;
        str = s;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                
                if(solve(i,j) == true){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        
        return s.substr(sp,maxlen);
    }



int main(){

    cout << longestPalindrome("abbbacde") << endl;
}