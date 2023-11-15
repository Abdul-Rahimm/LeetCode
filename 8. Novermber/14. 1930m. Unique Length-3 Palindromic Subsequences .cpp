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
int countPalindromicSubsequence_me(string s) {
    N = s.size();
    return helper(s, 3, 0, "");
}

int countPalindromicSubsequence(string s){
    int n = s.size();

    unordered_set<char> letters;

    for(char i : s)
        letters.insert(i);

    int ans = 0;
    for(char letter : letters){

         int left = -1;
        int right = -1;

        for(int i = 0 ; i < n ; i++){

            if(s[i] == letter){
                if(left == -1)
                    left = i;

                right = i;
            }
        }

        unordered_set<char> uni;
        for(int middle = left+1 ; middle < right ; middle++){
            uni.insert(s[middle]);
        }

        ans += uni.size();
    }

    return ans;
}
int main(){
    string a = "maaz";
    cout << countPalindromicSubsequence(a) << endl; 
}