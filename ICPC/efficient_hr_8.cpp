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
    
    for(int i = 0 ; i < column[0] ; i++){
        set<int> st;

        int take_i = vec[0][i];
        st.insert(take_i);

        for(int j = 0 ; j < column[1] ; j++){
            int take_j = vec[1][j];

            if(st.size() == 2)
                st.erase(vec[1][j-1]);

            if(st.find(take_j) == st.end())         st.insert(take_j);
            else                                    continue;

            for(int z = 0 ; z < column[2] ; z++){
                int take_z = vec[2][z];

                if(st.find(take_z) == st.end())     st.insert(take_z);
                else                                continue;

                st.erase(take_z);

                cout << take_i <<" "<< take_j <<" "<< take_z << endl;
                result++;
            }
        }
    }
    
    cout << result << endl;


}