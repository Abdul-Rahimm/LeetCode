// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
const int mod = 1e9 + 7;
 
void solve();
 
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
              
    while (tc--)
        solve();
              
    return 0;
}
 
void helper(vii ans, int i, int j, int k){



    // take_i = ans[][] + helper(ans, i, j+1, k);    


}
void solve(){
    int budget,classes;
    cin >> budget >> classes;

    int row = classes; 
    vector<vector<int>> vec(row); 

    vector<int> column(classes);//1 2 3

    for(int i = 0 ; i < classes; i++){
        cin >> column[i];

        int col = column[i];  

        vec[i] = vector<int>(col); 
        for(int j = 0; j < col; j++) 
            cin >> vec[i][j];
    }
        
      
    helper(vec, 0,0,0);


}