// link - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// Time Complexity - O(ElogV)
// Space Complexity - O(E)   + O( V + E )

class Solution {
    typedef pair<long long,long long> pi;
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pi> adj[n];
        int m = roads.size();
        for(int i=0;i<m;++i){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        // adjacency list is ready 
        
        vector<long long> dist(n,1e18);
        vector<long long> ways(n,0);
        
        dist[0] = 0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});
        ways[0] = 1;
        while(pq.empty()==0){
            pi top = pq.top();
            pq.pop();
            
            long long cost = top.first;
            long long node = top.second;
            
            for(auto it : adj[node]){
                long long dis = it.second;
                long long v = it.first;
                
                if(dist[v] > cost + dis){
                    dist[v] = (cost + dis);
                    ways[v] = ways[node];
                    pq.push({dist[v],v});
                }
                
                else if(dist[v]== cost + dis){
                    ways[v] =( ways[v] + ways[node]) % mod;
                }
                
            }
        }
        
        return ways[n-1];
        
    }
};
