#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll b[n+1],a[n+1];
	for(ll i=0;i<n;i++)
	  cin>>b[i];
	if(n<=2)
	 cout<<"0";
	else
	{
		int ans=INT_MAX;
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
			{
			int f=0;
				 a[0] = b[0] + i;
				 a[1] = b[1] + j;
				int c=0;
				if(a[0]!=b[0])c++;
				if(a[1]!=b[1])c++;
				int d=a[1]-a[0];
				for(int k=2;k<n;k++)
				{
					a[k]=a[k-1]+d;
					if(abs(a[k]-b[k]) > 1)
					{
					 	f=1;
					 	break;
					}
					else if(a[k]!=b[k])
					{
						c++;
					}
				}
				if(f!=1)
     		       ans=min(ans,c);
			}
		
		}
		if(ans==INT_MAX)
		 cout<<"-1";
		 else 
		 cout<<ans;
	}
}
