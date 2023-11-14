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
    cin >> tc;
              
    while (tc--)
        solve();
              
    return 0;
}
void print(vii ans){
    cout << endl;
    for(auto row: ans){
        for(int i:row)
            cout << i << " ";
    cout << endl;
    }
}
void solve(){
    unordered_map<int, vector<int>> mp;
    int rows, result = 0;
    cin >> rows;//3

    vector<vector<int>> vec(rows); //3 rows

    vector<int> column(rows);//1
    for(int i = 0 ; i < rows; i++){
        cin >> column[i];

        int col = column[i];  //3

        vec[i] = vector<int>(col); 

        for(int j = 0; j < col; j++) 
            cin >> vec[i][j];
    }
    
    









    cout << result << endl;


}