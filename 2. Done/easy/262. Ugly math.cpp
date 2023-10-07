#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef unordered_map<int,int> um;
typedef vector<int> vi;
int nextprime(int x){
    int num = x;
    
    while(true){
        int count = 0;
        for(int i = 1 ; i <= num/2 ; i++){
            if(num % i == 0)   
                count++;
        }
        if(count == 1 && num > x)  return num;
        num++;
    }
}
bool isUgly(int n) {
    int num = nextprime(5);
    while(num < 10000){
        if(n % num == 0)    return false;
        else{
            num = nextprime(num);
        }
    }
    return true;

}

bool isUgly_correct_math(int n) {
   if(n==0) return false;
    
        while(n%2==0){
            n=n/2;
        }
        while(n%3==0){
            n=n/3;
        }
        while(n%5==0){
            n=n/5;
        }
        if(n==1) return true;
    
        return false;
    

}

int main(){
    cout << isUgly(-2147483648) << endl;
    cout << isUgly(1) << endl;
    cout << isUgly(14) << endl;
    
} 