#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqq;//max heap

int lastStoneWeight(vector<int>& stones) {
    pqq pq;
    for(int i : stones) 
        pq.push(i);

    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if(first > second){
            pq.push(first-second);
        
    }
}
        if(pq.empty())
            return 0;
        else
            return pq.top();
}
int main(){
    vi nums{2,7,4,1,8,1};
    cout << lastStoneWeight(nums) << endl;

    vi nums2{1};
    cout << lastStoneWeight(nums2) << endl;
}

