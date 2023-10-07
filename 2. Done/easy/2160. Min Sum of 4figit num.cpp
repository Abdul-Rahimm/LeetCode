#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minimumSum(int num) {
    priority_queue<int> pq;
    int num1=0,num2=0,mul=1;

    while(num > 0){
        pq.push(num%10);
        num /= 10;
    }

    num2 += pq.top()*mul;
    pq.pop();

    for(int i = 0 ; i < 2 ; i++){
        num1 += pq.top()*mul;
        pq.pop();

        if(i < 1)
            mul *= 10;
    }

    num2 += pq.top()*mul;

    return num1+num2;

}
int main(){
    cout << minimumSum(2932) << endl;
    cout << minimumSum(4009) << endl;
    

}

