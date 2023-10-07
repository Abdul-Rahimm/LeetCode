#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int addDigits(int num) {
    if(num < 10)    return num;
    int x = 0;

    while(num > 0){
        x += num % 10;
        num /= 10;
    }
    return addDigits(x);
}
int two_ms(int num) {
        return 1 + (num-1)%9;    
    }
int main(){
    int t=1,num=38;


    cout << two_ms(num) << endl;
    // while(t--){
    //     cin >> num;
    //     cout << addDigits(num) << endl;
    // }
}