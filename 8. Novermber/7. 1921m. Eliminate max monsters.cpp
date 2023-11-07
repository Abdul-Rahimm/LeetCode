// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;


int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> diff(n);
        
        for(int i = 0 ; i < n ; i++){
            diff[i] = ceil( (float)dist[i] / speed[i]) ;
        }
        
        sort(diff.begin(),diff.end());

        int count = 1;
        int time  = 1;

        for(int i = 1; i < n ; i++){
            if(diff[i] - time <= 0)
                return count;

                count++;
                time++;
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