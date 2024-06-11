// link - geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Time Complexity - O(ElogV)
// Space Complexity - varies for queue , pq , set appraoch do it yourself
// refer to notes -- they are good !

class Solution
{
	public:
	typedef pair<int,int> pi;
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src){
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,src}); // distance , node
        
        while(pq.empty()==0){
            pi top = pq.top();
            int wt = top.first;
            int node = top.second;
            pq.pop();
            
            for(auto it : adj[node]){
                if(wt + it[1] < dist[it[0]]){
                    dist[it[0]] = wt + it[1];
                    pq.push({dist[it[0]],it[0]});
                }
            }
            
        }   
        return dist;
    }
};


class Solution
{
	public:
	typedef pair<int,int> pi;
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src){
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        set<pi> st;
        st.insert({0,src}); // distance , node
        
        while(st.empty()==0){
            pi top = *(st.begin());
            int wt = top.first;
            int node = top.second;
            st.erase(top);
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(wt + edW < dist[adjNode]){
                    
                    if(dist[it[0]]!=INT_MAX){
                        st.erase({dist[it[0]],it[0]});
                    }
                    dist[it[0]] = wt + it[1];
                    st.insert({dist[it[0]],it[0]});
                }
            }
            
        }   
        return dist;
    }
};
