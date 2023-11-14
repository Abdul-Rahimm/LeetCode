// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int N;  //5
unordered_set<string> st;

bool isPalindrome(string s){
    return (s[0] == s[2]);
}
int helper(string s, int len, int idx, string word){
    if(len == 0 || idx == N){
        if(isPalindrome(word) && st.find(word) == st.end() && !word.empty()){
            st.insert(word);
            cout << word << endl;
            return 1;
        }
        return 0;
    }
    
    //take
    int take = helper(s, len -1, idx + 1, word + s[idx]);

    //not take
    int notTake = helper(s, len, idx + 1, word);

    return take + notTake;

}
int countPalindromicSubsequence(string s) {
    N = s.size();
    return helper(s, 3, 0, "");
}

int main(){
    string a = "maaz";
    cout << countPalindromicSubsequence(a) << endl; 
}