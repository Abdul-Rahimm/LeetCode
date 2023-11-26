// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int rows, cols;

vector<string> solve(vector<vector<char>> &grid, vector<string> &words){

}
void print(vector<string>& vec) {
    for (string item : vec) 
        cout << item << " ";
    
    cout << endl;
}
template <typename T> void print(vector<vector<T>> grid){
    for(vector<T> row: grid){
        for(T i: row)
            cout << i << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<char>> grid {{'o','f','o','o','t'},{'v','o','q','u','o'},{'e','o','i','h','o'},{'r','t','g','g','f'}};
    vector<string> dict{"foot"};

    rows = grid.size();
    cols = grid[0].size();
    

    vector<string> ans = solve(grid,dict);
    print(ans);
    // print(coordinates);



}