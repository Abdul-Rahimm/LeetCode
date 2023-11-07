// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
void print(vi ans){
    for(int i:ans)
        cout << i << " ";
} 
void print(priority_queue<int, vector<int> , greater<int>> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> diff(n);
        priority_queue<int, vector<int> , greater<int>> pq;
        
        for(int i = 0 ; i < n ; i++){
            diff[i] = dist[i]/speed[i] ;
        }
        
        for(int i = 0 ; i < n ; i++){
            pq.push(diff[i]);
        }

        pq.pop();
        int count = 1;
        while(!pq.empty() && count != n){
            int top = pq.top();
            pq.pop();

            if(top > count)
                count++;
            else    
                return count;
        }

        return count;
    }

int main(){
    int n;
    cin >> n;
    vector<int> dist(n),speed(n);

    for(int i = 0 ; i < n ; i++){
        cin >> dist[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> speed[i];
    }

    cout << eliminateMaximum(dist,speed) << endl;
    // eliminateMaximum(dist,speed);

}