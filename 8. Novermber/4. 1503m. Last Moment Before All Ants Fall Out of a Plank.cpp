// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    
    return max(right[0],left[left.size()-1]);
}

int getLastMoment_mik(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        
        for(int &i : right){
            result = max(result, n-i);
        }
        
        for(int &i : left){
            result = max(result, i);
        }
        
        
        return result;
    }

int main(){
    vi left{4,3};
    vi right{0,1};

    
    cout << getLastMoment(4,left,right) << endl;
}