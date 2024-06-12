// link - https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// Time Complexity - O(E)
// Space Complexity - O(N+E) + O( N +E )

class Solution {
    typedef pair<int,int> pi;
    typedef pair<int,pi> ppi;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(0);

        // first lets create our adjaceny list 
        vector<pi> adj[n];
        int m = flights.size();
        for(int i =0;i<m;++i){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }


        // also we need to gnore the iteraton if stops > k
        queue<ppi> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.push({0,{src,0}});

        while(q.empty()==0){
            ppi top = q.front();
            q.pop();

            int stops = top.first;
            int dis = top.second.second;
            int node = top.second.first;


            if(stops > k)
                continue;
            for(auto it : adj[node]){
                int cost = it.second;
                int child = it.first;

                if(dist[child] > cost + dis){
                    dist[child] = cost + dis;
                    q.push({stops + 1 , {child,dist[child]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
