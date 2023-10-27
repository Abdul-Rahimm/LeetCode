#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size(), result = 0;

    vector<int> count(n,1);

    for(int i = 1 ; i < n ; i++){
        if(ratings[i] > ratings[i-1]){
            count[i] = max(ratings[i],ratings[i-1]+1);
        }
    }

    for(int i = n-2 ; i >= 0 ; i--){
        if(ratings[i] > ratings[i+1]){
            count[i] = max(ratings[i],ratings[i+1]+1);
        }
    }

    for(int i : count)
        result += i;

    return result;
    
}

