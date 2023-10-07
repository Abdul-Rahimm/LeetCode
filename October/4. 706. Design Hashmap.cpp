// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<pair<int,int>> vpr;
// typedef vector<vi> vvi;
 
void print(vpr v){
    for(auto &pair:v){
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
}
void remove(vpr &v,int key){
    auto it = v.begin();

    while(it != v.end()){
        if(it->first == key){
            it = v.erase(it);
            return;
        }
        else
            it++;
    }
}
int main(){
    vpr v{{10,42},{11,32},{13,22},{12,21},{3,2}};
    print(v);
    remove(v,10);
    print(v);


}