// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;

int rows,cols;

vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}, 
                            {-1,-1},{-1,1},{1,-1},{1,1}};

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

                if(helper(grid,word,0,i,j,0,vis))
                    return true;

            }

        }
    }

    return false;
}

vector<string> solve(vector<vector<char>> grid, vector<string> dict){
    vector<string> ret;

    for(string word: dict){
        if(solver(grid,word))
            ret.push_back(word);
    }

    return ret;
}

template <typename T>
void print(vector<T>& vec) {
    for (T item : vec) 
        cout << item << " ";
    
    cout << endl;
}
// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ

typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;

vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}, 
                            {-1,-1},{-1,1},{1,-1},{1,1}};

bool helper(vcc grid, string word, int idx,int i, int j, int word_size,vbb &vis);
bool solver(vcc grid, string word);
vector<string> solve(vcc grid, vector<string> dict);
template <typename T> void print(vector<T>& vec);

int main(){
    vector<vector<char>> grid {{'c','a','t'},{'r','r','e'},{'t','o','n'}};
    vector<string> dict{"tz","toon","cater","moon","art","not","eat","ton","tan"};

    rows = grid.size();
    cols = grid[0].size();

    vector<string> ans = solve(grid,dict);
    print(ans);


}