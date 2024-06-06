// link - geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Time Complexity - O(N) + O(N + 2E)
// Space Complexity - O(N) + O(N)

class Solution {
    private:
    bool dfs(int node,int parent,vector<int> adj[],int vis[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] && it!=parent){
                return 1;
            }
            else if(vis[it]==0){
                if(dfs(it,node,adj,vis)==1)
                    return 1;
            }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(i,-1,adj,vis))
                    return true;
        }
        
        return false;
    }
};
