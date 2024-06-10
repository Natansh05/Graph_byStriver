// link - https://www.geeksforgeeks.org/problems/eventual-safe-states/1
//  Time Complexity  - O(N + N +E) + O(klogk)
// Space Complexity - O(N+E) + O(N) + O(N)

class Solution {
    vector<int> topoSort(int n,vector<int> outdegree,vector<int> adj[]) {
	   // indegree store ho chuka hai
	   queue<int> q;
	   for(int i=0;i<n;++i){
	       if(outdegree[i]==0)
                q.push(i);
	   }
	   
	   vector<int> topo;
	   while(q.empty()==0){
	       int front = q.front();
	       q.pop();
	       topo.push_back(front);
	       
	       for(auto it : adj[front]){
	           outdegree[it]--;
	           if(outdegree[it]==0)
	                q.push(it);
	       }
	   }
	   
	   sort(topo.begin(),topo.end());
       return topo;
	}
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> inv[n];
        vector<int> outdegree(n,0);
        for(int node = 0;node<n;++node){
            for(auto it : adj[node]){
                inv[it].push_back(node);
            }
            outdegree[node] = adj[node].size();
        }
        
        //  now  out main adjacency list is inv and 
        // main reference is outdegree vali list
        return topoSort(n,outdegree,inv);
    }
};
