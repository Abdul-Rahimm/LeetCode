#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;

int m,n;
vvi directions{{0,1},{0,-1},{1,0},{-1,0}};

bool find(vector<vector<char>>& board, int i,int j,int idx,string &word){
    if(idx >= 1)  return true;

    if(i < 0 || j < 0 || i >= m || j >= n )
        return false;

    if(board[i][j] != word[idx])
        return false;

    char temp = board[i][j];    //save the char 
    board[i][j] = '*';         //mark visited

    //backtracking logic
    for(auto &dir: directions){
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if(find(board,new_i,new_j,idx+1,word))
            return true;
    }

    board[i][j] = temp;
    return false;
    
}
bool exist(vector<vector<char>>& board, string word) {
    m = board.size();       //rows
    n = board[0].size();    //cols
    int l = word.size();

    if(m*n < l)
        return false;
        
    for(int i = 0; i < m; i++){
        for(int j = 0 ; j < n ; j++){

            if(board[i][j] == word[0] && find(board,i,j,0,word))
                return true;
        }
    }
    
    return false;
}


int main(){
    vvc board{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    cout << exist(board,"ABCCED") << endl;

    vvc board1{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    cout << exist(board1,"SEE") << endl;

    vvc board2{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    cout << exist(board2,"ABCB") << endl;

}