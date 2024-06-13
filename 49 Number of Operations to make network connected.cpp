// link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// Time Complexity - O(V+E)
// Space Complexity - O(N)


class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    int cnt = 0;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        cnt = 0;
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
        if(ult_u == ult_v) {
            ++cnt;
            return; 
        }
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
    int makeConnected(int n, vector<vector<int>>& conn) {
        int nc = 0,m = conn.size();
        DisjointSet ds(n);
        for(int i=0;i<m;++i){
            ds.UnionBySize(conn[i][0],conn[i][1]);
        }

        int extra_edges = ds.cnt;
        for(int i=0;i<n;++i){
            if(ds.parent[i]==i)
                ++nc;
        }

        if(extra_edges >= nc-1)
            return nc-1;
        else
            return -1;

    }
};
