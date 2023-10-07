#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> pascal(rowIndex + 1);

    pascal[0].push_back(1);
    for(int i = 1 ; i <= rowIndex  ; i++){
        pascal[i].push_back(1);
        for(int j = 0 ; j < i-1 ; j++){
            pascal[i].push_back(pascal[i-1][j]+pascal[i-1][j+1]);
        }
        pascal[i].push_back(1);
    }
    
    return pascal[rowIndex];

}

int main(){
    int t=3,row;
    vector<int> result;
    
    while(t--){
        cin >> row;
        result = getRow(row);
    
    
        for(int number : result)
            cout << number << " ";
            cout << endl;
        
}
}