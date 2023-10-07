#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int pivotInteger(int n) {
    // vector<int> nums;
    // for(int i = 1 ; i <= n ; i++)
    //     nums.push_back(i);
    int total = 0;
    for(int i = 1; i <= n ; i++)
        total += i;

    int prefix = 0, oneless = 0;

    for(int i = 1 ; i <= n ; i++){ // 1 2 3 4 5 6 7 8
        prefix = prefix + i;
        if(i > 1)
            oneless = oneless + i - 1;

        if(total - oneless == prefix)
            return i;
    }

    return -1;
}
int main(){
    cout << pivotInteger(8) << endl;
    cout << pivotInteger(1) << endl;
    cout << pivotInteger(4) << endl;
    
}