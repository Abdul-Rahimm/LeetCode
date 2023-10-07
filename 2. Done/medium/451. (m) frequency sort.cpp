#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqq;//max heap

string frequencySort(string s) {
    map<char,int> mp;
    for(char i : s)
        mp[i]++;
    
    
    priority_queue<pair<int,char>> pq;
    for(auto pair: mp){
        pq.push({pair.second,pair.first});
    }

    string ans = "";
    while(!pq.empty()){
        int num = pq.top().first;
        char c = pq.top().second;

        for(int i = 0 ; i < num ; i++){
            ans += c;
        }
        pq.pop();
    }

    return ans;
}

void print(map<char,int> mp){
    for(auto pair:mp){
        cout << pair.first << " " << pair.second << endl;
    }
}
void print(priority_queue<pair<int,char>> pq){
    while(!pq.empty()){
        char cha = pq.top().second;
        int num = pq.top().first;
        cout << num << " " << cha << endl;
        pq.pop();
    }
}

int main(){
    cout << frequencySort("tree") << endl;
    cout << frequencySort("cccaaa") << endl;
    cout << frequencySort("Aabb") << endl;
    cout << frequencySort("bbaaaiizzzz") << endl;
    
    
}

