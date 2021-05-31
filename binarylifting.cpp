int parent[100004][18];
int level[100005]; 
void dfs(int node, int par, int lev) {
    
    level[node] = lev;
    parent[node][0]= par; 
    for(int i = 0;i<17;i++) {
        parent[node][i+1] = parent[parent[node][i]][i]; 
    }
    
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node, lev + 1); 
        }
    }
}
