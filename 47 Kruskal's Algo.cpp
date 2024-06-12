// link - geeksforgeeks.org/problems/minimum-spanning-tree/1
// Time Complexity - O(2E log (2E)) + O(2E) + O(N+E)
// Space Complexity - O(V) + O(V)


class DisjointSet{
    private:
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u , int v){
        int ult_u = findUPar(u);
        int ult_v  = findUPar(v);

        if(ult_u == ult_v)
            return;
        if(rank[ult_u]  < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v]= ult_u;
        }
        else{
            parent[ult_u] = parent[ult_v];
            rank[ult_v] ++;
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

class Solution
{
	public:
	typedef pair<int,pair<int,int>> ppi;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]){
        
        vector<ppi> edges;
        for(int i=0;i<n;++i){
            for(auto it : adj[i]){
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        
        sort(edges.begin(),edges.end());
        int ans =0;
        DisjointSet ds(n);
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ans+=wt;
                ds.UnionBySize(u,v);
            }
        }
        
        return ans;
    }
};
