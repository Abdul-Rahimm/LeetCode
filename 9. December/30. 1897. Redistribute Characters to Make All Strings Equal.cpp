// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
bool makeEqual(vector<string>& words) {
        int n = words.size();
        
       int array[26];
        
        for(string i : words){
            for(char c: i){
               array[c - 'a']++;
            }
        }
        
        auto lambda = [&](int freq){ //& bahar k elements ko andar access kr skte 
            return freq % n == 0;
        };

        return all_of(begin(array),end(array), lambda);
        
        //can also be written like this
        // return all_of(begin(array),end(array), [&](int freq){ //& bahar k elements ko andar access kr skte 
        //     return freq % n == 0;
        // });
    }

int main(){



}