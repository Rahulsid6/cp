bool prime[1000001];
int c[10000001];
void Sieve()
{
    
 	c[0]=0;
 	c[1]=0;
 	prime[1]=1;
    for (int p = 2; p * p <1000001; p++)
    {
      
        if (prime[p] == 0)
        {
           
            for (int i = p * p; i < 1000001; i += p)
                prime[i] = 1;
        }
    }
    int j=1;
    c[2]=0;
    for(int i=3;i<1000001;i++)
    {

    	if(prime[i]==0)
    	{
    		j++;
    	}
    		if(prime[j]==0)
    		{
    			c[i]=c[i-1]+1;
    		}
    		else
    		{
    			c[i]=c[i-1];
    		}

    }
}
