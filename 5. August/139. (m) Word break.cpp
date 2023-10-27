#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

unordered_map<string,bool> memo;
bool isprefix(string s,string prefix){
    if(prefix.length() > s.length())
        return false;

    for(int i = 0; i < prefix.length() ; i++){
        if(prefix[i] != s[i])
            return false;
    }

    return true;
}
bool wordBreak(string s, vector<string>& wordDict) {
    if(memo.count(s) > 0)       return memo[s];
    if(s.empty())               return true;

    for(string i: wordDict){
        if(isprefix(s,i)){
            string suffix = s.substr(i.length());
            
            if(wordBreak(suffix,wordDict)){
                memo[s] = true;
                return true;
                }
        }
    }

    memo[s] = false;
    return false;
}


int main(){
    vector<string> words{"leet","code"};
    cout << wordBreak("leetcode",words) << endl;
    
    vector<string> words1{"apple","pen"};
    cout << wordBreak("applepenapple",words1) << endl;

    vector<string> words2{"cats","dogs","sand","and","cat"};
    cout << wordBreak("catsandog",words2) << endl;

}