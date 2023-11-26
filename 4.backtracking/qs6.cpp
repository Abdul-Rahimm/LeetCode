// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int rows, cols;
vector<vector<vector<int>>> coordinates;
vector<vector<int>> current;

struct VectorHash {
    size_t operator()(const std::vector<int>& vec) const {
        std::hash<int> hasher;
        size_t hash = 0;
        for (int value : vec) {
            hash ^= hasher(value) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
unordered_set<vector<int> , VectorHash> st;

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

        vector<int> occurence{new_i,new_j, i,j};
        if(st.find(occurence) != st.end())
            continue;
        
        st.insert(occurence);

        if(helper(grid,word,idx+1,i + new_i,j + new_j,word_size+1,vis))
            return true;
    }

    current.pop_back();
    vis[i][j] = false;  //upon exiting
    return false;
}

bool solver(vector<vector<char>> grid, string word,int &sx, int &sy){
    int orig_sx = sx, orig_sy = sy;
   for(sx = orig_sx; sx < rows ; sx++){
        for(sy = 0 ; sy < cols ; sy++){

            if(word[0] == grid[sx][sy]){
                vector<vector<bool>> vis(rows, vector<bool>(cols, false));

                if(helper(grid,word,0,sx,sy,0,vis))
                    return true;   
            }
        }
    }

    return false;
}

void solve(vector<vector<char>> &grid, string &word, int &sx, int &sy){
    int orig_sx = sx, orig_sy = sy;

    if(solver(grid,word,sx,sy)){
        coordinates.push_back(current);
    }
    current.clear();

    if(sx >= rows-1 && sy >= cols-1)        //we have reached the end of the matrix
        return;                             //stop exploring

    if((sx != orig_sx || sy != orig_sy) && (sx != 0 && sy != 0))
        st.clear();

    solve(grid,word,sx,sy);                 //matrix is left to explore

}
void print(vector<string>& vec) {
    for (string item : vec) 
        cout << item << " ";
    
    cout << endl;
}
void print(vector<vector<vector<int>>> ans){
    int count = 1;
    for(vector<vector<int>> two_d : ans){
        cout << "Occurence " << count << ": ";
        count++;

        for(vector<int> row: two_d){
            int x = 0;
            cout << "{";
            for(int i : row){
                if(x == 0)
                    cout << i << " , ";
                else    
                    cout << i ;
                x++;
            }
             cout << "} ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char>> grid  {{'o','f','o','o','t'},
                                {'q','o','q','u','o'},
                                {'a','o','i','h','o'},
                                {'r','t','g','g','f'}};
    string word = "foot";

    rows = grid.size();
    cols = grid[0].size();
    
    int startx = 0, starty = 0;
    solve(grid,word,startx,starty);
  
    print(coordinates);
}