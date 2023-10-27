#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
void print(vector<vector<int>> combinations){
    // Display the generated combinations
    for (auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void backtrack(int n,int k, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(currentCombination);
        return;
    }

    for (int i = start; i <= n; ++i) {
        currentCombination.push_back(i);
        backtrack(n, k - 1, i + 1, currentCombination, result);
        currentCombination.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    
    vector<int> currentCombination;
    backtrack(n, k, 1, currentCombination, result);
    return result;
}


void solve(int start,int n, int k, vector<int> &temp){
    if(k == 0){
        result.push_back(temp);
        return;
    }

    if(start > n)   return;

    temp.push_back(start); //element le kr explore  
    solve(start+1, n, k-1, temp);

    temp.pop_back();      //element bina liye explore
    solve(start+1, n, k, temp);
 
}
vector<vector<int>> youtube(int n, int k){
    vector<int> temp;

    solve(1, n, k, temp);
    return result;
}


int main() {
    vector<vector<int>> combinations = combine(4,2);

    print(combinations);

    return 0;
}
