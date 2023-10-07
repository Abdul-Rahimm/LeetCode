#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

string makeSmallestPalindrome(string s) {
        int ans = s;
        int start = 0;
        int end = s.size()-1;
        
        while(start < end){
            
            if(ans[start] < ans[end])
                ans[end] = ans[start];
            else if(ans[start] > ans[end])
                ans[start] = ans[end];
            
            start++;    end--;
        }
    }