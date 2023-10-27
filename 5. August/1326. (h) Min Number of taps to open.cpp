#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minTaps(int n, vector<int>& ranges) {
    vector<int> startend(n+1 , 0);

    for(int i = 0 ; i < n+1 ; i++){
        int start  = max(0,i-ranges[i]);
        int end    = min(n,i+ranges[i]);

        startend[start] = max(startend[start] , end); 
    }

    int taps = 0, maxend = 0, currentend = 0;

    for(int i = 0 ; i <= n ; i++){
        if(i > maxend)
            return -1;

        if(i > currentend){
            taps++;
            currentend = maxend;
        }

        maxend = max(maxend,startend[i]);
    }

    return taps;
}
int main(){
    vector<int> nums{3,4,1,1,0,0},nums2{0,0,0,0};
    cout << minTaps(5,nums) << endl;
    cout << minTaps(4,nums2) << endl;
    

}

