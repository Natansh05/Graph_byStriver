// link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// Time Complexity - O(ElogV) + O(V)
// Space Complexity - O(N) + O(K)+ O(N) + O(N) + O(N)


class Solution {
    typedef pair<int,int> pi;
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // first hum log adjancecny list bana lete hai
        
        vector<pi> adj[n+1];
        
        for(int i=0;i<m;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        //  at this point adj list is created
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[1] = 0;
        vector<int> parent(n+1,1);
        
        pq.push({0,1});
        
        while(pq.empty()==0){
            pi top = pq.top();
            pq.pop();
            int node = top.second;
            int dis = top.first;
            
            for(auto it : adj[node]){
                int wt = it.second;
                int v = it.first;
                
                if(dist[v] > dis + wt){
                    dist[v] = dis + wt;
                    parent[v] = node;
                    pq.push({dist[v],v});
                }
            }
        }
        
        //  at this point our parent array is filled with the data we needed
        
        if(dist[n]==INT_MAX)
            return {-1};
        vector<int>path;
        int sum = dist[n];
        int node = n ;
        
        while( parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(sum);
        reverse(path.begin() , path.end());
       return path;
    }
    
    
};
