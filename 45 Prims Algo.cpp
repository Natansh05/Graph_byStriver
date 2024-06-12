// link - geeksforgeeks.org/problems/minimum-spanning-tree/1
// Time Complexity - O(ElogE)
// Space Complexity - O(V) + O(E)

class Solution
{
	public:
	typedef pair<int,int> pi;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> vis(n,0);
        pq.push({0,0});
        
        int sum = 0;
        while(pq.empty()==0){
            auto top = pq.top();
            pq.pop();
            
            
            int wt = top.first;
            int node = top.second;
            
            if(vis[node]==1)
                continue;
            sum+=wt;
            
            vis[node] = 1;
            
            for(auto it : adj[node]){
                int child = it[0];
                int dis = it[1];
                
                if(!vis[child]){
                    pq.push({dis,child});
                }
            }
        }
        
        return sum;
    }
};
