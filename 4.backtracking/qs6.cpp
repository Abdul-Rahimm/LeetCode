// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int rows, cols;
vector<vector<vector<int>>> coordinates;
vector<vector<int>> current;

vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

bool helper(vector<vector<char>> grid, string word, int idx,int i, int j, int word_size,vector<vector<bool>> &vis){ 
    if(i >= rows || j >= cols || i < 0 || j < 0 || word_size > word.size() || word[idx] != grid[i][j])
        return false;   //out of bound
    
    if(vis[i][j] == true)
        return false;       //cant go back from where came
    vis[i][j] = true;       //mark true

    vector<int> record{i,j};    //make record to be inserted for coordinated
    current.push_back(record);  //insert record

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

                if(helper(grid,word,0,i,j,0,vis))
                    return true;   
            }
        }
    }

    return false;
}

void solve(vector<vector<char>> &grid, string &word){

    if(solver(grid,word)){
        coordinates.push_back(current);
    }
        current.clear();
    
}
void print(vector<string>& vec) {
    for (string item : vec) 
        cout << item << " ";
    
    cout << endl;
}
void print(vector<vector<vector<int>>> ans){
    for(vector<vector<int>> two_d : ans){
        int count = 1;
        cout << "Occurence " << count << ": ";

        for(vector<int> row: two_d){
            int i = 0;
            cout << "{";
            for(int i : row){
                if(i == 0)
                    cout << i << " , ";
                else    
                    cout << i ;
                i++;
            }
             cout << "} ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char>> grid {{'o','f','o','o','t'},{'v','o','q','u','o'},{'e','o','i','h','o'},{'r','t','g','g','f'}};
    vector<string> dict{"foot"};
    string word = "foot";

    rows = grid.size();
    cols = grid[0].size();
    
    solve(grid,word);
    
    print(coordinates);
}