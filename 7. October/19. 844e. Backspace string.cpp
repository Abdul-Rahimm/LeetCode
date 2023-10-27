// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
 bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        
        for(char i : s){
            if(i == '#'){
                if(s1.empty() == false)
                    s1.pop();
            }
            else
                s1.push(i);
        }
        for(char i : t){
            if(i == '#'){
                if(s2.empty() == false)
                    s2.pop();
            }    
            else
                s2.push(i);
        }
        
        string a = "", b = "";
        while(!s1.empty()){
            a += s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            b += s2.top();
            s2.pop();
        }
        
        return a==b;
    }

int main(){

    string s,t;
    cin >> s >> t;
    cout << backspaceCompare(s,t) << endl;

    // string s = "a",d = "b";
    // bool status = s==d;
    // cout << status << endl;

}