#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string word = "";
    
    do{
        columnNumber--; //for edge case Z
        int num = columnNumber % 26;
        
        char c = num + 'A';
        word = c + word;

        columnNumber /= 26;
    
    }while(columnNumber > 0);
        
    return word;
}
   
int main(){
    cout << convertToTitle(52) << endl;
    cout << convertToTitle(1) << endl;
    cout << convertToTitle(28) << endl;
    cout << convertToTitle(701) << endl;
    
}