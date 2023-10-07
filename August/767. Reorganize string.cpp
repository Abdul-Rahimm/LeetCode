#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqq;//max heap
typedef pair<int,char> pr;

string reorganizeString(string s) {
    map<char,int> mp;
    int len = s.size();
    string word = "";
    
    for(char i : s){
        mp[i]++;                    //count frequency
        if(mp[i] > ceil(len/2.0))   //possibility nai
             return "";
    }

    priority_queue<pr,vector<pr>> pq;   
    
    for(auto pair:mp)
        pq.push(make_pair(pair.second,pair.first));

    while(pq.size() >= 2){
        //extract top 2 elements and add their chars 
        auto x1 = pq.top();         pq.pop();   
        auto x2 = pq.top();         pq.pop();

        //word += char and decrease freq of char
        word.push_back(x1.second);  x1.first--;
        word.push_back(x2.second);  x2.first--;

        //push them back if their freq > 0
        if(x1.first > 0)
            pq.push(x1);
        
        if(x2.first > 0)
            pq.push(x2);
    }

    if(!pq.empty()) //only one thing left. last char
        word.push_back(pq.top().second);

    return word;
}
int main(){
    cout << reorganizeString("aab") << endl;   
    cout << reorganizeString("aaabcd") << endl;    
    cout << reorganizeString("aabbccddee") << endl;    
    
}

