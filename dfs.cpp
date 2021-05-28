void dfs(int x)
{
	visited[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(visited[v[x][i]]==0)
		dfs(v[x][i]);
	}
}
