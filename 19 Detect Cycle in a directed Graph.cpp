// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time Complexity - O(N + N + E)
// Space Complexity - O(N) + O(N)--recursion stack space

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],int vis[]){
        vis[node] = 2;
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis)==1)
                    return true;
            }else if(vis[it]==2)
                return true;
        }
        vis[node] = 1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        int vis[n]= {0};
        for(int i=0;i<n;++i){
            if(vis[i]==0)
                if(dfs(i,adj,vis)==1)
                    return true;
        }
        return false;
    }
};
