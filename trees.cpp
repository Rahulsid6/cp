int height[200001];
int subsize[200001];
 vector<int>v[2000001];
vector<int> ans;
void calsubsize(int node,int parent)
{
 	subsize[node]=1;
 	for(auto it: v[node])
	{
		if(it!=parent)
		{
			calsubsize(it,node);
			subsize[node]+=subsize[it];
		} 
	}
}
void calheight(int node,int parent,int c)
{
	height[node]=c;
	for(auto it: v[node])
	{
		if(it!=parent)
		{
			calheight(it,node,c+1);
		} 
	}
}

signed main() {

    fio;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    calheight(1,-1,0);
    calsubsize(1,-1);
    for(int i=1;i<=n;i++)
    {
    	//ans[i]=height[i]-subsize[i];
    
    	ans.pb(height[i]-subsize[i]+1);
    
    }
   \
    sort(all(ans));
    reverse(all(ans));    
  int sum=0;
    for(int i=0;i<k;i++)
    {
    	sum+=ans[i];
    	
    }
    cout<<sum;
}
