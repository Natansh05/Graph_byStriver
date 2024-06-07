// link - https://leetcode.com/problems/is-graph-bipartite/description/
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
    bool check(int start,vector<vector<int>>& adj,vector<int> &colour){
        queue<int> q;
	    q.push(start);
	    colour[start] = 0;
	    
	    while(q.empty()==0){
	        int node = q.front();
	        q.pop();
	        
	        for(auto it : adj[node]){
	            if(colour[it]==-1){
	                colour[it] = !colour[node];
	                q.push(it);
	            }else if(colour[it]==colour[node]){
	                return 0;
	            }
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
	            if(check(i,adj,colour)==false)
	                return false;
	            else
	                continue;
	        }
	    }
	    return 1;
    }
};
