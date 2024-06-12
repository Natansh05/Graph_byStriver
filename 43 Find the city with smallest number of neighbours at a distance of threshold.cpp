// link - https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
// Time Complexity - O(N^3) for warshall algo and O(N^2 + N*E*log(N)) for dijsktra
// Space Complexity - O(N^2)

class Solution {
    vector<vector<pair<int, int>>> adj;
public:
    int dijkstra(int src, int limit, int n){
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<>> q;
        vector<int> seen(n, 0);
        q.push({0, src});
        dis[src] = 0;
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            int u = node.second, d = node.first;
            if(seen[u])continue;
            seen[u] = 1;
            for(auto ch : adj[u]){
                if(dis[ch.first] > d + ch.second){
                    dis[ch.first] = d + ch.second;
                    q.push({dis[ch.first], ch.first});
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i != src && dis[i] <= limit){
                cnt++;
            }
        }
        return cnt;
    }



    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj.resize(n);
        for(auto ed : edges){
            int u = ed[0], v=ed[1], w = ed[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int mincnt = n-1;
        int ind = -1;

        for(int i=0; i<n; i++){
            int cnt = dijkstra(i, distanceThreshold, n);
            if(cnt > mincnt)continue;
            mincnt = min(mincnt, cnt);
            if(mincnt == cnt)ind = i;

        }

        return ind;


    }
};







class Solution {
    vector<vector<pair<int, int>>> adj;
public:
    int dijkstra(int src, int limit, int n){
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<>> q;
        vector<int> seen(n, 0);
        q.push({0, src});
        dis[src] = 0;
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            int u = node.second, d = node.first;
            if(seen[u])continue;
            seen[u] = 1;
            for(auto ch : adj[u]){
                if(dis[ch.first] > d + ch.second){
                    dis[ch.first] = d + ch.second;
                    q.push({dis[ch.first], ch.first});
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i != src && dis[i] <= limit){
                cnt++;
            }
        }
        return cnt;
    }



    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj.resize(n);
        for(auto ed : edges){
            int u = ed[0], v=ed[1], w = ed[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int mincnt = n-1;
        int ind = -1;

        for(int i=0; i<n; i++){
            int cnt = dijkstra(i, distanceThreshold, n);
            if(cnt > mincnt)continue;
            mincnt = min(mincnt, cnt);
            if(mincnt == cnt)ind = i;

        }

        return ind;


    }
};
