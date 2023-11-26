// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;

int rows,cols;
vector<vector<pair<int,int>>> coordinates;
vector<pair<int,int>> current;

vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

bool helper(vector<vector<char>> grid, string word, int idx,int i, int j, int word_size,vector<vector<bool>> &vis){ 
    if(i >= rows || j >= cols || i < 0 || j < 0 || word_size > word.size() || word[idx] != grid[i][j])
        return false;   //out of bound
    
    if(vis[i][j] == true)
        return false;       //cant go back from where came
    vis[i][j] = true;       //mark true

    if(word_size == word.size()-1 && word[idx] == grid[i][j])
        return true;
    
    for(auto pair : dir){
        int new_i = pair.first;
        int new_j = pair.second;

        if(helper(grid,word,idx+1,i + new_i,j + new_j,word_size+1,vis))
            return true;
    }

    vis[i][j] = false;  //upon exiting
    return false;
}

bool solver(vector<vector<char>> grid, string word){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){

            if(word[0] == grid[i][j]){
                vector<vector<bool>> vis(rows, vector<bool>(cols, false));

                if(helper(grid,word,0,i,j,0,vis)){
                    return true;
                    pair<int,int> pr = make_pair(i,j);
                    current.push_back(pr);
                }
            }

        }
    }

    return false;
}

vector<string> solve(vector<vector<char>> grid, vector<string> dict){
    vector<string> ret;

    for(string word: dict){
        if(solver(grid,word)){
            ret.push_back(word);
            coordinates.push_back(current);
            current.clear();
        }
    }

    return ret;
}


void print(vector<string>& vec) {
    for (string item : vec) 
        cout << item << " ";
    
    cout << endl;
}
template <typename T>
void print(vector<vector<T>> grid){
    for(vector<T> row: grid){
        for(char i: row)
            cout << i << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<char>> grid {{'o','f','o','o','t'},{'v','o','q','u','o'},{'e','o','i','h','o'},{'r','t','g','g','f'}};
    vector<string> dict{"foot"};

    rows = grid.size();
    cols = grid[0].size();
    // print(grid);

    vector<string> ans = solve(grid,dict);
    print(ans);
    print(coordinates);


}