// link  - https://www.geeksforgeeks.org/problems/topological-sort/1
// Time Complexity - O(N + N + E)
// Space Complexity - O(N + N + N)

class Solution
{
    private:
	void dfs(int node,vector<int> adj[],int vis[],stack<int> &st){
	    if(vis[node])
	        return;
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        dfs(it,adj,vis,st);
	    }
	    st.push(node);
	    return;
	}
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) {
	    stack<int> st;
	    int vis[n] = {0};
	    
	    for(int i=0;i<n;++i){
	        if(vis[i]==0)
	            dfs(i,adj,vis,st);
	    }
	    vector<int> ans;
	    while(st.empty()==0){
	        ans.push_back( st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};
