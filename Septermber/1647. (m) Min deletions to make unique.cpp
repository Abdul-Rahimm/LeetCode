#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minDeletions(string s) {
    unordered_map<char,int> mp;
    unordered_set<int> st;
    int total = 0;

    for(char i :s){
        mp[i]++;
    }

    for(auto &pair:mp){
        while((st.find(pair.second) != st.end()) && !st.empty()){
            total++;
            pair.second--;
        }
        st.insert(pair.second);
    }

    return total;
}
int main(){
    cout << minDeletions("aaaaabbbbbccccc") << endl;
    // cout << minDeletions("aaabbbcc") << endl;
    // cout << minDeletions("ceabaacb") << endl;
    
    

}