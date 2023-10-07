#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef priority_queue<int> pqq;//max heap

int largestInteger(int num) {
    vector<pair<int,int>> pr;   //num,parity
    pqq even,odd;

    while(num > 0){
        int digit = num%10;
        
        if(digit % 2 == 0){
            pr.push_back({digit,0});
            even.push(digit);
        }
        else{ 
            pr.push_back({digit,1});
            odd.push(digit);
        }

        num /= 10;
    }

    int len = pr.size();
    int number = 0;
    
    for(int i = len-1 ; i >= 0 ; i--){
        number *= 10;
        if(pr[i].second == 1){
            number += odd.top();
            odd.pop();
        }
        else{
            number += even.top();
            even.pop();
        }
    }

    return number;
}
int main(){
    cout << largestInteger(1234) << endl;
    cout << largestInteger(65875) << endl;

}

