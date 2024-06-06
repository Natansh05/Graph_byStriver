// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Time Complexity - O(N) + (N+2E)
// Space Complexity - O(N) + O(N)
class Solution {
    private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(i!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(detect(i,adj,vis))
                    return true;
        }
        
        return false;
    }
};
