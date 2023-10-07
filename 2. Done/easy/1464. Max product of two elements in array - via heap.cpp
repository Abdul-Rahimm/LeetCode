#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int maxProduct(vector<int>& nums) {
    priority_queue<int, vi, greater<int>> pq;

    for(int i : nums){
        pq.push(i);

        if(pq.size() > 2)
            pq.pop();
    }

    int result = pq.top()-1;
    pq.pop();
    result *= pq.top()-1;
    return result;
        
}
int main(){
    vi nums{3,4,5,2};
    cout << maxProduct(nums) << endl;

    vi nums2{1,5,4,5};
    cout << maxProduct(nums2) << endl;

  
  }