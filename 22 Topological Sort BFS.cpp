// link - https://www.geeksforgeeks.org/problems/topological-sort/1
// Time Complexity - O(N + N +E)
// Space Complexity - O(N) + O(N)

  class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
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
	   
	   return topo;
	}
	
};
