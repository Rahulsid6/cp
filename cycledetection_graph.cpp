int visited[1000001];
bool dfs(int node,int parent)
{
	visited[node]=1;
	for(auto i: adj[node])
	{
		if(visited[i]==0)
		{
			dfs(i,node);
		}
		else
		{
			if(i!=parent)
			{
				return true;
			}
		}
	}
	return false;
}
