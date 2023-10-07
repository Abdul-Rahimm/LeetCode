#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> ways{1},previous{1,1};
        if(numRows == 1){
            result.push_back(ways);
            return result;
        }
        else{
            result.push_back(ways);
            result.push_back(previous);
            
        for(int i = 2 ; i < numRows ; i++){
            ways.clear();   ways.push_back(1);
            for(int j = 0 ; j <= i-2 ; j++){
                int num = previous[j] + previous[j+1];
                ways.push_back(num);
            }
            ways.push_back(1);
            result.push_back(ways);
            previous = ways;
        }
        return result;
}
}
vector<vector<int>> fast_generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        if(numRows<2)
            return ans;

        for(int i=1;i<numRows;++i){
            ans[i].push_back(1);
            for(int j=0;j<i-1;++j){
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }

        return ans;
    }
int main(){
    int t=3,numrows;
    vector<vector<int>> result;
    
    while(t--){
        cin >> numrows;
        result = fast_generate(numrows);
    
    for(vector<int> row: result){
        for(int number : row)
            cout << number << " ";
        cout << endl;
        }
}
}