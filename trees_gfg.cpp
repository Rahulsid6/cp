#include <iostream>
using namespace std;
int height = 0; 
vector<int> adj[100005];
int parent[100005]; 
void dfs(int node, int par, int level) {
    height = max(height, level); 
    parent[node] = par; 
    cout << node; 
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node, level + 1); 
            cout << node; 
        }
    }
    
}
int subtree[100005]; 
void dfs(int node, int par) {
    subtree[node] = 1; 
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node); 
            // after the dfs of it is over, can i say that the subtree size of it would have been computed
            subtree[node] += subtree[it]; 
        }
    }
}



void solve() {
    int n;
    cin >> n;
    for(int i = 0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    dfs(1,-1,1);
    cout << height << endl; 
}

int subtree[100005], level[100005]; 
vector<int> contri; 
void dfs(int node, int par, int lev) {
    subtree[node] = 1; 
    level[node] = lev; 
    for(auto it : adj[node]) {
        if(it != par) {
            dfs(it, node, lev + 1); 
            // after the dfs of it is over, can i say that the subtree size of it would have been computed
            subtree[node] += subtree[it]; 
        }
    }
}

void solve() {
    // input 
    dfs(1,-1, 1); 
    for(int i = 1;i<=n;i++) {
        contri.push_back(level[node] - subtree[node]); 
    }
    sort(contri.begin(), contri.end()); 
    reverse(contri.begin(), contri.end()); 
    int ans = 0;
    for(int i = 0;i<k;i++) {
        ans += contri[i]; 
    }
    cout << ans; 
}

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


int findKthParent(int node, int k) {
    for(int i = 0;i<=log2(k);i++) {
        if(k & (i<<i)) {
            node = parent[node][i]; 
        }
    }
    return node; 
}

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


int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u,v)]; 
}

void solve() {
    // input 
    
    dfs(1,0,1);
    while(q--) {
        int num;
        cin >> num;
        vector<int> queries;
        int deepest = 0; 
        for(int i = 0;i<num;i++) {
            int x;
            cin >> x;
            queries.push_back(x); 
            if(level[x] > level[deepest]) {
                deepest = x;
            }
        } 
        
        int flag = 1; 
        for(auto it : queries) {
            int lc = lca(it, deepest);
            if(lc == it || dist(lc, it) == 1) {
                continue;
            }
            flag = 0;
            break; 
        }
        if(flag) cout << "YES\n";
        cout << "NO\n"; 
    }
}

