#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

 bool isSubsequence(string s, string t) {
        int pos = 0;
        int size_short = s.size();
        int long_size = t.size();
        
        for(int i = 0 ; i < long_size ; i++){
            if(s[pos] == t[i])
                pos++;
            
            if(pos == size_short)
                return true;
        }
        
        return false;
    }