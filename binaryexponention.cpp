int power(int x,int n)
{
	int ans=1;
	while(n)
	{
		if(n%2){
			ans=ans*x;
			n--;
		}
		else
		{
			x=x*x;
			n=n/2;
		}
	}
	return ans;
}
