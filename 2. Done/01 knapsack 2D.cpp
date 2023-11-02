// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int items = 4, bag = 7;
vector<int> profit(items);
vector<int> weight(items);

int knapsack(int w,int idx){
    if(w > bag || idx >= items)
        return 0;

    int take = 0;
    if(w + weight[idx] <= bag)
    take = profit[idx] + knapsack(w + weight[idx] ,idx + 1);

    int not_take = knapsack(w,  idx + 1);

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
    cout << knapsack(0,0) << endl;


}