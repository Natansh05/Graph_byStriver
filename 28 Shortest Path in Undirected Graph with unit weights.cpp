// link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Time Complexity - O(N + 2E)
// Space Complexity - O(N) + O(N +2E)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        
        // first we need to create our adjacency list
        vector<int> adj[n];
        for(int i=0;i<m;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // adjacency list is created
        
        vector<int> dist(n,INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        
        while(q.empty()==0){
            auto node = q.front();
            
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[node]!=INT_MAX && dist[node] + 1 < dist[it] ){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        // now wherever we have used INT_MAX , we need to replace it with -1;
        for(int i=0;i<n;++i){
            if(dist[i]==INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
