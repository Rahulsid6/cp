int findKthParent(int node, int k) {
    for(int i = 0;i<=log2(k);i++) {
        if(k & (i<<i)) {
            node = parent[node][i]; 
        }
    }
    return node; 
}
