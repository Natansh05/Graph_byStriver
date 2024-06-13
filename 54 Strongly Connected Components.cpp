// link - https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/0
// Time Complexity - O(N + N + E)
// Space Complexity - O(N)

class Solution
{
	public:
	void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it]==0)
                dfs(it,adj,vis,st);
        }
        st.push(node);
        return;
        
    }
    
    void dfs2(int node,vector<vector<int>> &adj,vector<bool> &vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it]==0)
                dfs2(it,adj,vis);
        }
        return;
        
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        vector<bool> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;++i){
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        
        vector<vector<int>> inv(n);
        for(int i=0;i<n;++i){
            vis[i]=0;
            for(auto it : adj[i]){
                inv[it].push_back(i);
            }
        }
        
        int cnt = 0;
        while(st.empty()==0){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                ++cnt;
                dfs2(node,inv,vis);
            }
        }
        return cnt;
        
    }
};
