#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool isPalindrome1(int x) {
    //make reversed number 
}

bool isPalindrome(int x){
    if(x < 0)       return false;
    string num = to_string(x);

    int first = 0, last = num.size() -1;
    while(first < last){
        if(num[first] != num[last])
            return false;
        first++,    last--;
    }

    return true;
}
int main(){
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(10) << endl;
    
}