#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int,int>> pr;
vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    //lambda comparater func
    auto issafe = [&](int x,int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    result[0][0] = 0;
    pq.push(make_pair(0,{0,0}));

    while(!pq.empty()){

        int diff = pq.top().first;
        auto xy = pq.top().second;  //co ordinate
        pq.pop();

        int x = xy.first;
        int y = xy.second;

        //priority queue so the first value
        //in result vector is actually the least 
        if(x == m-1 && y == n-1)
            return diff;

        for(auto dir:directions){
            int new_x = x + dir[0];
            int new_y = y + dir[1]; 

            if(issafe(new_x,new_y)){
                int absdiff = abs(heights[x][y] - heights[new_x][new_y]);
                int maxdiff = max(diff,absdiff);

                if(maxdiff < result[new_x][new_y]){
                    result[new_x][new_y] = maxdiff;
                    pq.push({maxdiff,{new_x,new_y}});
                }
            }
        }
    }
    return result[m-1][n-1];
}
int main(){
    

}