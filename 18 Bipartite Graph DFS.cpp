// link - https://leetcode.com/problems/is-graph-bipartite/description/
// Time Complexity - O(N + N+2E)
// Space Complexity - O(N) + O(N)

class Solution {
    bool dfs(int parent,vector<vector<int>>& adj,vector<int> &colour){
        for(auto it : adj[parent]){
            if(colour[it]==-1){
                colour[it]= !colour[parent];
                if(dfs(it,adj,colour)==false)
                    return false;
            }else if(colour[it]==colour[parent]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> colour(n,-1);
	    for(int i=0;i<n;++i){
	        if(colour[i]==-1){
                colour[i]= 0;
	            if(dfs(i,adj,colour)==false)
	                return false;
	            else
	                continue;
	        }
	    }
	    return 1;
    }
};
