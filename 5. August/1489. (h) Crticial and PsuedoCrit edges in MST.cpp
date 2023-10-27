#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef priority_queue<int> pqq;//max heap

int N;// no of edges
class unionfind{ //har baar alag alag dsu call horha hai thats y
    public:
        vi parent;
        vi rank;

        unionfind(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(x == parent[x]){
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void union(int x,int y){
            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent == y_parent){
                return ;
            }

            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }

        }
};

int kruskal(vii edges,int skip,int add){
    int sum = 0;
    unionfind uf(N);
    
    if(add != -1){  //laazmi add this edge
        uf.union(edges[add][0],edges[add][1]);
        sum += edges[add][2];
    }

    for(int i = 0 ; i < edges.size() ; i++){
        if(i == skip)   //skip this edge and check
            continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        int parent_u = uf.find(u);
        int parent_v = uf.find(v);

        if(parent_u != parent_v){
            uf.union(u,v);
            sum += wt;
        }
    }

    return sum;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
   
    N = n;
    // 1. append original indexes
    for(int i = 0 ; i < edges.size() ; i++){
        edges[i].push_back(i);
    }

    // 2. Sort based on index
    auto lambda = [&](vector<int> &vec1, vector<int> &vec2){
        return vec1[2] < vec2[2]; //sorting based on wts
    };
    sort(edges.begin(),edges.end(),lambda);

    // 3. Find mst weight using kruskal algo
    int mst_wt = kruskal(edges,-1,-1);  //no skip rn

    vi critical, sudo;

    // 4. find which edges are critical and which are sudo
    for(int i = 0 ; i < edges.size() ; i++){
        
        if(kruskal(edges,i,-1) > mst_wt){       //skipping the ith edge
            critical.push_back(edges[i][3]);    //push the critical wt index
        }
        else if(kruskal(edges,-1,i) == mst_wt){
            sudo.push_back(edges[i][3]);
        }
    }

    return {critical,sudo};
}

void print(vii ans){
    for(auto row:ans){
        for(int i:row)
            cout << i << " ";
    cout << endl; 
    }
}
int main(){
    vii edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vii ans = findCriticalAndPseudoCriticalEdges(5,edges);
    print(ans);
}