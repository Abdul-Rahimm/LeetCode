// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int hammingWeight(uint32_t n) {
    int count = 0;

    while(n > 0){
        int bit = n && 1;
        n >> 1;

        if(bit == 1) count++;
    }

    return count;
}

int main(){
    cout << hammingWeight(128) << endl;

}