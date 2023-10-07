#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef priority_queue<int> pqq;//max heap
typedef deque<int> deq;

long long pickGifts(vector<int>& gifts, int k) {
    pqq pq;
    long long total = 0;

    for(int i:gifts){
        pq.push(i);
        total += i;
    }

    for(int i = 0 ; i < k ; i++){
        int num = floor( sqrt(pq.top()));
        total = total - pq.top() + num;
        pq.push(num);
        pq.pop();
    }

    return total;

}
int main(){
    vi nums{25,64,9,4,100};
    cout << pickGifts(nums,4) << endl;

    vi nums2{1,1,1,1};
    cout << pickGifts(nums2,4) << endl;
}

