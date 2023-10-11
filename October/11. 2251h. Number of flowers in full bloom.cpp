// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<vector<int>> vii;
typedef vector<int> vi;

void print(vi nums){
    for(int i: nums)
        cout << i << " ";
}

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> start,die,ans;
    
    for(vi i:flowers){
        start.push_back(i[0]);
        die.push_back(i[1]);
    }
    
    sort(start.begin(),start.end());
    sort(die.begin(),die.end());
    
    for(int i = 0 ; i < die.size() ; i++){
        int num = people[i];

        int x = upper_bound(start.begin(),start.end(),num) - start.begin();
        int y = lower_bound(die.begin(),die.end(),num) - die.begin();
        
        ans.push_back(x-y);
    }

    return ans;
}
 
int main(){
    vii flowers {{1,6},{3,7},{9,12},{4,13}};
    vi people{2,3,7,11};
    vi ans = fullBloomFlowers(flowers,people);
    print(ans);


}