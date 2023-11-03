// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> ans;
        string push = "Push", pop = "Pop";
        
        for(int i = 0, j = 1 ; i < len, j <= n ; j++){
            if(i == len)
                return ans;
            ans.push_back(push);
            if(target[i] == j){
                i++;
                continue;
            }
            else
                ans.push_back(pop);
        }   
        
        return ans;
    }

void print(vector<string> ans){
    for(string i: ans){
        cout << i << " ";
    }
}
int main(){
    // int t, n;
    // cin >> t >> n;

    // vector<int> array(t);

    // for(int i = 0 ; i < t ; i++)
    //     cin >> array[i];
    vector<int> array{1,2};
    vector<string> ans = buildArray(array,4);
    print(ans);

}