// link - https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Time Complexity - O(N^2) + O(K) + O(K+E)
// Space Complexity - O(K) + O(K) + O(K) + O(K+E) + O(K)

class Solution{
    
    private:
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
	
	void compare(int i,vector<int> adj[],string dict[]){
        string first = dict[i];
        string second = dict[i+1];
        
        int len = min(first.size(),second.size());
        
        for(int j=0;j<len;++j){
            if(first[j]!=second[j]){
                adj[first[j]-'a'].push_back(second[j]-'a');
                break;
            }
        }
	}
    public:
    string findOrder(string dict[], int n, int k) {
        
        vector<int> adj[k];
        
        for(int i=0;i<n-1;++i){
            compare(i,adj,dict);
        }
            
        vector<int> ans = topoSort(k,adj);
        string s = "";
        
        for(auto it : ans){
            s+= (char)(it + 'a');
        }
        return s;
        
        
    }
};
