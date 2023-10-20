// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int items = 4, bag = 7;
vector<int> profit(items);
vector<int> weight(items);

int knapsack(int w,int p,int idx){

    int prof = p;
    if(w > bag || idx > items)
        return 0;
    if(idx == items)
        return prof;
    

    int take = knapsack(w + weight[idx], p + profit[idx] , idx + 1);
    int not_take = knapsack(w, p , idx + 1);

    return max(take,not_take);

}

int main(){
    cin >> items >> bag;
    for(int i = 0 ; i < items ; i++){
        cin >> profit[i];
    }
    for(int i = 0 ; i < items ; i++){
        cin >> weight[i];
    }
    cout << knapsack(0,0,0) << endl;


}