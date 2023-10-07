#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool ispalindrome(string word){
    int start=0, end=word.size()-1;
        while(start < end){
            if(word[start] != word[end])
                return false;
            start++,end--;
        }
    return true;
}
string firstPalindrome(vector<string>& words){
    bool status;
    for(string word: words){
        status = ispalindrome(word);
        if(status)  return word;
    }

    return "";
}

int main(){
    vector<string> words{"def","ghi"};  
    cout << firstPalindrome(words) << endl;
    
}
