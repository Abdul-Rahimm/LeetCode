#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef unordered_map<int,int> um;
typedef vector<int> vi;

bool isHappy(int n) {
    while(n > 9){
        int sum = 0;
        int temp = n;

        while(temp > 0){
            int a = temp%10;
            sum += a*a;
            temp /= 10;
        }
        n = sum;
    }

    if(n == 1 || n == 7)
        return true;
    return false;
    
}

int main(){
    cout << isHappy(19) << endl;
    cout << isHappy(2) << endl;
    
}