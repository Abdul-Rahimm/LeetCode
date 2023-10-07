#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqq;//max heap
bool isprefix(string temp, string s){
    for(int i = 0 ; i < temp.size() ; i++){
        if(temp[i] != s[i])
            return false;
    }
    return true;
}
bool repeatedSubstringPattern_mine(string s) {
    
    string word = ""; // a ab
    string temp;

    for(int i = 0 ; i < s.size()/2 ; i++){
        word += s[i];
        
        if(s.size() % word.size() == 0 ){
            //check for condition
            temp = s;
            while(!temp.empty()){
                if(isprefix(temp,s))
                    temp = temp.substr(word.size());
                else    
                    break;
            }
            if(temp.empty())
                return true;
        } 
    }

    return false;
}
bool repeatedSubstringPattern_mik(string s){
    int len = s.size();

    for(int i = len/2 ; i >= 1 ; i--){

        if(len%i == 0){
            int times = len/i;

            string pattern = s.substr(0,i);
            string newword = "";

            while(times--)
                newword += pattern;
        
            if(newword == s)
                return true;
        }
    }
    return false;
}
bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;i--){    
            string first = s.substr(0,n-i);
            string second = s.substr(i);
            cout << first << " " << second << " " << i << endl;
            
            if(n%i==0){                       
                if(s.substr(0,n-i)==s.substr(i))return true;         
            }
        }
        return false;
    }
int main(){
    cout << repeatedSubstringPattern("abcabcabc") << endl;
    
}

