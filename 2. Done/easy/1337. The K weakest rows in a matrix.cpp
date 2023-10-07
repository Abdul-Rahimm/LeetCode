#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pr;
//typedef priority_queue<int> pq;//max heap
typedef priority_queue<pr, vector<pr>, greater<pr>> pqq;
typedef deque<int> deq;

void print(pqq pq){
    stack<pair<int,int>> stk;

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        stk.push(pq.top());
        pq.pop();
    }

    while(!stk.empty()){
        pq.push(stk.top());
        stk.pop();
    }
}
void print(vi nums){
    for(int i:nums)
        cout << i << " ";
    cout << endl;
}
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> ans;
    pqq pq;//ones,index
    int rows = mat.size();
    int cols = mat[0].size();

    int i = 0;
    for(auto row: mat){
        int ones = accumulate(row.begin(),row.end(),0);
        pq.push({ones,i});
        i++;
    }

    for(int i = 0 ; i < k ; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}   
int main(){
    vii mat{{1,1,0,0,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,1,1,1,1}};
    vi ans = kWeakestRows(mat,3);
    print(ans);

    vii mat2{{1,0,0,},
             {1,1,1,},
             {1,0,0,},
             {1,0,0,}};
    ans = kWeakestRows(mat2,2);
    print(ans);
}