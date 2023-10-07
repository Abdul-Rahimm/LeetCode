#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int i = 1;
    here:
    if(digits[digits.size() - i] == 9){
        digits[digits.size() - i] = 0;
        i++;
        if(digits.size() <= i -1)
            digits.insert(digits.begin(),1);
        else{
            if(digits[digits.size() - i] == 9)
                goto here;
            else    
                digits[digits.size() - i]++;
        }     
    }
    else{
        digits.back() += 1;
    }
    
    return digits;
}

int main(){
    vector<int> digits{1,2,3,4};
    digits = plusOne(digits);
    for(int i: digits)
        cout << i << " ";

}