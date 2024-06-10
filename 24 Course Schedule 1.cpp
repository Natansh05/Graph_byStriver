// link - https://leetcode.com/problems/course-schedule/
// Time Complexity - O(N + N +E )
// Space Complexity - O(N + N )


// COURSE SCHEDULE 1 IN PREVIOUS QUESTION USED
class Solution {
    bool topoSort(int n, vector<int> adj[]) {
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
	   
	   return topo.size()==n;
	}
public:
    bool canFinish(int n, vector<vector<int>>& list) {
        // here , we will use the concept that if the cycle exists for prerequisites in learning any course
        // then courses cannot be finished in any case
        

        // first we need to create adjacency list for the given tasks
        // [a,b] represents that b is prerequisite for a so for mapping
        // adj[b].push_back(a) should be the case
        int m = list.size();
        vector<int> adj[n];
        for(int i=0;i<m;++i){
            adj[list[i][1]].push_back(list[i][0]);
        }
        
        // adjacency list is created
        return topoSort(n,adj);
    }
};
