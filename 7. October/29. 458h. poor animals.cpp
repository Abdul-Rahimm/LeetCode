// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie;
        int pigs = 0;
        
        while(pow(t+1,pigs) < buckets)
            pigs++;
        
        return pigs;
        
    }
int main(){
    int t,a,c;
    cin >> t >> a >> c;
    cout << poorPigs(t,a,c) << endl;

    

}