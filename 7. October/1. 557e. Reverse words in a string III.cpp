// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef array<int,2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;
 

string reverseWords(string s) {
    stack<char> st;
    int n = s.size();
    string ans;

    for(int i = 0 ; i < n; i++){
        if(i == n-1)
            st.push(s[i]);

        if((s[i] == ' ' || i == n-1) && !st.empty()){
            while(st.empty() == false){
                ans.push_back(st.top());
                st.pop();
            }
            if(i != n-1)
                ans.push_back(' ');
        }
        else
            st.push(s[i]);
    }
    return ans;
}
int main(){

    cout << reverseWords("Let's take LeetCode contest") << endl;
    cout << reverseWords("God Ding") << endl;

}