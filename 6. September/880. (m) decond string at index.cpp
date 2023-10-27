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
 


string decodeAtIndex(string s, int k) {
    int n = size.length();
    long long size = 0;

    for(char &ch : s){

        if(isdigit(ch)){
            size = size * (ch-'0');
        }
        else{
            size++;
        }
    }

    for(int i = n ; i >= 0 ; i--){
        k = k % size;

        if(k == 0 && isalpha(s[i])){
            return string(1, s[i]);
        }

        if(isalpha(s[i])){
            size--;
        }
        else{
            size = size/(s[i] - '0');
        }
    }

    return "";
}


