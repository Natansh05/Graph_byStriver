// link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0
// Time Complexity - O( N + 3M) + O(N + N +E) + O(N) + O(N)
// Space Complexity - O(N + 3M) + O(N) + O(N) + O(N)

class Solution {
    void dfs(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
	    if(vis[node])
	        return;
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        int v = it.first;
	        if(!vis[v])
	            dfs(v,adj,vis,st);
	    }
	    st.push(node);
	    return;
	}
	
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        // find topo sort
        stack<int> st;
	    int vis[N] = {0}; 
	    
	    for(int i=0;i<N;++i){
	        if(vis[i]==0)
	            dfs(i,adj,vis,st);
	    }
	    
	    vector<int> dist(N,INT_MAX);
	    dist[0] = 0;
	    
	   // hamara topo sort ab stack me aa chuka hai
	    while(st.empty()==0){
	        int node = st.top();
	        st.pop();
	        
	        for(auto it : adj[node]){
	            int v = it.first;
	            int wt = it.second;
	            
	            if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){
	                dist[v] = dist[node] + wt;
	            }
	        }
	    }
	    
	    
	    for(int i=0;i<N;i++){
	        if(dist[i]==INT_MAX)
	            dist[i] = -1;
	    }
	    return dist;
        
        
    }
};
