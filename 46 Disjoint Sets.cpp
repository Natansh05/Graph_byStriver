// Time Coplexity - O(4* alpha)---constant
// Space Complexity - O(4* alpha)---constant

// for doing all the things in a stream for a graph this is used.


#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{
    private:
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u , int v){
        int ult_u = findUPar(u);
        int ult_v  = findUPar(v);

        if(ult_u == ult_v)
            return;
        if(rank[ult_u]  < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v]= ult_u;
        }
        else{
            parent[ult_u] = parent[ult_v];
            rank[ult_v] ++;
        }
    }
    
    void UnionBySize(int u, int v) {
        int ult_u = findUPar(u); 
        int ult_v = findUPar(v); 
        if(ult_u == ult_v) return; 
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v; 
            size[ult_v] += size[ult_u]; 
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v]; 
        }
    }

};


int main(){
    DisjointSet ds(7);
    ds.UnionBySize(1, 2); 
    ds.UnionBySize(2, 3); 
    ds.UnionBySize(4, 5); 
    ds.UnionBySize(6, 7); 
    ds.UnionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.UnionBySize(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
    return 0;
}
