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
int threshold;
void solve();
 
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    cin >> threshold;

    while (tc--)
        solve();
              
    return 0;
}
 
void print(vi ans){
    for(int i : ans){
        if(i >= threshold)
            cout << 1 << " ";
        else   
            cout << 0 << " ";
    }
    cout << endl;
}
void solve(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0 ; i < n ; i++)
        cin >> nums[i];

    // ---------------------------
    
    vector<int> diff(n-2);

    for(int i = 0 ; i < n-2 ; i++){

        int difference  = abs(nums[i+1] - nums[i]);
        int difference2 = abs(nums[i+2] - nums[i+1]);

        int d = abs(difference2 - difference);
        diff[i] = d;
    }

    print(diff);
}