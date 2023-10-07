#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
int m,n;
vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();

    queue<pair<int,int>> q;
    vii result(m, vector<int>(n, -1));

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(mat[i][j] == 0){
                result[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int,int> pr = q.front();
        q.pop();

        int i = pr.first;
        int j = pr.second;

        for(auto dir:directions){
            int new_i = i + dir.first;
            int new_j = j + dir.second;

            if(new_i >= 0 && new_i < m && new_j >=0 && new_j < n && result[new_i][new_j] == -1 ){
                result[new_i][new_j] = result[i][j] + 1;
                q.push({new_i,new_j});
            }
        }
    }

    return result;
}
void print(vii ans){
    for(auto row: ans){
        for(int i:row)
            cout << i << " ";
    cout << endl;
    }
}
int main(){
    vii mat{{0,0,0},{0,1,0},{0,0,0}};
    vii ans = updateMatrix(mat);
    print(ans);

}

