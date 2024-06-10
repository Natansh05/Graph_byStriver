// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time Complexity - O(N + N +E)
// Space Complexity - O(N) + O(N)

class Solution {
    vector<int> topoSort(int n, vector<int> adj[]) {
	    vector<int> indegree(n,0);
	    for(int i=0;i<n;++i){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	   // indegree store ho chuka hai
	   queue<int> q;
	   for(int i=0;i<n;++i){
	       if(indegree[i]==0)
                q.push(i);
	   }
	   
	   vector<int> topo;
	   while(q.empty()==0){
	       int front = q.front();
	       q.pop();
	       topo.push_back(front);
	       
	       for(auto it : adj[front]){
	           indegree[it]--;
	           if(indegree[it]==0)
	                q.push(it);
	       }
	   }
	   
       if(topo.size()==n)
	        return topo;
        return {};
	}
public:
    vector<int> findOrder(int n, vector<vector<int>>& list) {
        int m = list.size();
        vector<int> adj[n];
        for(int i=0;i<m;++i){
            adj[list[i][1]].push_back(list[i][0]);
        }
        
        // adjacency list is created
        return topoSort(n,adj);
    }
};
