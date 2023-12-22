// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
int func(string str){
    return count(str.begin(),str.end(), '0');
}
//these changes are being done from the new-function branch
int main(){

    //just the main function

    string str = "100111001";
    cout << func(str) << endl;

}