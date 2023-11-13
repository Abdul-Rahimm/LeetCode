// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<char,int> pr;

void print(priority_queue<pr, vector<pr>, greater<pr>> pq){
    while(!pq.empty()){
        char c = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        cout << c << " : " << idx << endl;
    }
   
}


typedef pair<char,int> pr;
bool isvowel(char i){
    i = tolower(i);
    if(i == 'a' ||i == 'e' ||i == 'i' ||i == 'o' ||i == 'u')
        return true;
    
    return false;
}
string sortVowels(string s) {
    priority_queue<pr, vector<pr>, greater<pr>> pq;         //int(s[i]) --> index
    vector<int> indexes;

    for(int i = 0 ; i < s.size() ; i++){
        if(isvowel(s[i])){
            pq.push({s[i],i});
            indexes.push_back(i);
        }
    }
    
    print(pq);

    int count = 0;
    while(!pq.empty()){
        char c = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        s[indexes[count]] = c;
        count++;
    }



    return s;
}

int main(){
    cout << sortVowels("lEetcOde") << endl;
    // cout << sortVowels("lymph") << endl;
}