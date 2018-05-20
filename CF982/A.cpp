#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n,f=1;
    cin>>n;
    cin>>s;
    
    if(n==1 && s[0]=='0')
	      f=0;
    else if (n==2)
	{
	     if((s[0]=='0' && s[1]=='0')||(s[0]=='1' && s[1]=='1'))
	      f=0;
	}
	else 
	{
	    for(int i=1;i<n-1;i++)
	    {
	    	if(s[i]=='0' && s[i-1]=='0' && s[i+1]=='0')
			{
				f=0;
				break;
			}
	      if(s[i]=='1' && s[i-1]=='1')
		  {
		  	f=0;
		  	break;
		  }
	    } 	
	    if(n!=1 && s[n-2]=='1' && s[n-1]=='1')
	      f=0;
	    if((s[0]=='0' && s[1]=='0')||(s[n-1]=='0' && s[n-2]=='0'))
	     f=0;
	}
	
	if(f==1)
	cout<<"Yes";
	else 
	cout<<"No";
    return 0;
}
