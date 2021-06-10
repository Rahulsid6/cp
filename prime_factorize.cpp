map<int,int> mp;

void factorize(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		
			int cnt=0;
			if(n%i==0)
			{
				while(n%i==0)
				{
					n=n/prime[i];
					cnt++;
				}
				mp[prime]=cnt;
			}
	}
	if(n>1)
		mp[n]=1;
}
