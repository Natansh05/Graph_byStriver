link - https://www.geeksforgeeks.org/problems/eventual-safe-states/1
// Time Complexity - O(N + N +E )
// Space Complexity - O(N + N + N)
class Solution {
    private:
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,pathVis)==1)
                    return true;
            }else if(vis[it]==1 && pathVis[it]==1)
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        int vis[n] = {0};
        int pathVis[n] = {0};
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                dfs(i,adj,vis,pathVis);
            }
        }
        
        for(int i=0;i<n;++i){
            if(pathVis[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};
