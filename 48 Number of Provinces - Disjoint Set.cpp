// link - https://leetcode.com/problems/number-of-provinces/description/
// Time Complexity - O(N^2) + O(N)
// Space Complexity - O(N) + O(N)

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
    int findCircleNum(vector<vector<int>>& conn) {
        int n = conn.size();
        DisjointSet ds(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(conn[i][j]==1)
                    ds.UnionBySize(i,j);
            }
        }

        int cnt = 0;
        for(int i=0;i<n;++i){
            if(ds.parent[i]==i)
                ++cnt;
        }

        return cnt;
    }
};
