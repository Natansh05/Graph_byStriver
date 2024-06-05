// link - geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> bfs;
        int vis[n] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(q.empty()==0){
            int top = q.front();
            bfs.push_back(top);
            q.pop();
            
            for(auto it : adj[top]){
                if(vis[it]!=1){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
            
        }
        return bfs;
        
    }
};
