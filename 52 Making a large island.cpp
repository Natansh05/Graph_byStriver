// link - https://leetcode.com/problems/making-a-large-island/description/
// Time Complexity - O(N*M*4)
// Space Complexity - o(N*M)

class DisjointSet {
public: 
    vector<int> rank, parent, size; 
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
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int maxi  = 0;
        DisjointSet ds(n*m);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        // step 1
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    for(int k =0;k<4;++k){
                        int nrow = i+ delrow[k];
                        int ncol = j + delcol[k];
                        set<int> st;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                            int adj = nrow*m + ncol;
                            int node = i*m + j;
                            ds.UnionBySize(adj,node);
                        }
                    }
                }
            }
        }
        
        
        
        // step 2
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;++k){
                        int nrow = i+ delrow[k];
                        int ncol = j + delcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                            int adj = nrow*m + ncol;
                            int new_par = ds.findUPar(adj);
                            st.insert(new_par);
                        }
                    }
                    
                    int temp = 0;
                    for(auto it : st){
                        temp+=ds.size[it];
                    }
                    maxi = max(maxi,temp + 1);
                    
                }
            }
        }
        
        for(int num = 0 ; num<n*m;++num){
            maxi = max(maxi , ds.size[ds.findUPar(num)]);
        }
        
        
        return maxi;
    }
};
