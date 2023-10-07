#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int> pqq;//max heap

int fillCups(vector<int>& amount) {
    pqq pq;

    for(int i : amount)
        pq.push(i);

    int time = 0;
    while(pq.top() != 0){
        int first = pq.top();
        pq.pop();

        if(pq.top() > 0){
            pq.push(pq.top()-1);
            pq.pop();
        }
        pq.push(first-1);

        time++;   
    }
    return time;
}
int main(){
    vi nums{1,4,2};
    cout << fillCups(nums) << endl;

    vi nums2{5,4,4};
    cout << fillCups(nums2) << endl;

    vi nums3{5,0,0};
    cout << fillCups(nums3) << endl;
    

}

