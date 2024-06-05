// link - geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?page=1
// Space Complexity - O(N)
// Time Complexity - O(N + 2E)

class Solution {
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(vis[it]==0)
                dfs(it,adj,vis,ans);
        }
        return;
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        int vis[n] = {0};
        vector<int> ans;
        dfs(0,adj,vis,ans);
        return ans;
    }
};
