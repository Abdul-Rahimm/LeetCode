#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isPalindrome(string s) {
    string ret;
    for(char a:s){
        char add = tolower(a);
        if((add >= 97 && add <= 122) || (add >= 48 && add <= 57))
            ret += add;
    }
        
    int start=0, end=ret.size()-1;
    while(start < end){
        if(ret[start] != ret[end])
            return false;
        start++,end--;
    }

    return true;
    

}

int main(){  
    cout << isPalindrome("0P") << endl;
    
}
