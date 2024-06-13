// link - https://www.geeksforgeeks.org/problems/number-of-islands/1
// Time Complexity - O(N*M*4)
// Space Complexity - O(M*N)

class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    int cnt =0;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u); 
        int ult_v = findUPar(v); 
        if(ult_u == ult_v) return; 
        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v; 
        }
        else if(rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u; 
        }
        else {
            parent[ult_v] = ult_u; 
            rank[ult_u]++; 
        }
    }

    void UnionBySize(int u, int v) {
        int ult_u = findUPar(u); 
        int ult_v = findUPar(v); 
        if(ult_u == ult_v) return; 
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v; 
            size[ult_v] += size[ult_u]; 
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v]; 
        }
    }
}; 


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        vector<int> ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col]==1){
                ans.push_back(ds.cnt);
                continue;
            }
            vis[row][col] = 1;
            ds.cnt++;
            
            int delrow[]  = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
            
            for(int i=0;i<4;++i){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && vis[nrow][ncol]==1){
                    int curr = row*m + col;
                    int adj = nrow*m + ncol;
                    if(ds.findUPar(curr)!=ds.findUPar(adj)){
                        ds.UnionBySize(curr,adj);
                        ds.cnt--;
                    }
                }
            }
            ans.push_back(ds.cnt);
            
        }
        return ans;
    }
};
