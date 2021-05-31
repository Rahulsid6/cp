int lca(int u, int v) {
    if(level[v] < level[u]) swap(u, v); 
    
    int dist = level[v] - level[u]; 
    v = findKthParent(v, dist); 
    
    if(u==v) return u; 
    
    for(int i = 17;i>=0;i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i]; 
            v = parent[v][i]; 
        }
    }
    
    return parent[u][0]
    
}
