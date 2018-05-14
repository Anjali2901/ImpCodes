//http://codeforces.com/contest/979/problem/B 
//NA 

#include<bits/stdc++.h>
using namespace std;
int low[100],high[100];
int main()
{
	string a,b,c;
	long long int n,a1,a2,a3;
	cin>>n;
	cin>>a;
	cin>>b;
	cin>>c;
	long long int len=a.length();
	for(int i=0;i<27;i++)
	{
		low[i]=0;
		high[i]=0;
	}
	for(int i=0;i<a.length();i++)
	{
		if(isupper(a[i]))
		high[a[i]-'A']++;
		else
		low[a[i]-'a']++;
	}
	int even=0,odd=0;
	long long int m=0;
	for(int i=0;i<27;i++)
	{
		if(low[i]>m)m=low[i];
		if(high[i]>m)m=high[i];
		if(low[i]%2==0)even=1;
		else odd=1;
		if(high[i]%2==0)even=1;
		else odd=1;
	}
	if((m+n)>len)
	{
		//n=n-(len-m);
		if((n-len)%2==0)
		{
			if(even==1)
			a1=len;
			else
			a1=len-1;
		}
		else
		{
			if(odd=1)
			a1=len;
			a1=len-1;
		}
	}
	else
	a1=min(m+n,len);
	for(int i=0;i<27;i++)
	{
		low[i]=0;
		high[i]=0;
	}
		for(int i=0;i<b.length();i++)
	{
		if(isupper(b[i]))
		high[b[i]-'A']++;
		else
		low[b[i]-'a']++;
		
	}
	 m=0;
	for(int i=0;i<27;i++)
	{
		if(low[i]>m)m=low[i];
		if(high[i]>m)m=high[i];
		
	}	if((m+n)>len)
	{
		if((n-len)%2==0)
		{
			if(even==1)
			a2=len;
			else
			a2=len-1;
		}
		else
		{
			if(odd=1)
			a2=len;
			a2=len-1;
		}
	}
	else
	a2=min(m+n,len);
	odd=even=0;
	for(int i=0;i<27;i++)
	{
		low[i]=0;
		high[i]=0;
		if(low[i]%2==0)even=1;
		else odd=1;
		if(high[i]%2==0)even=1;
		else odd=1;
	}
		for(int i=0;i<c.length();i++)
	{
		if(isupper(c[i]))
		high[c[i]-'A']++;
		else
		low[c[i]-'a']++;
		
	}
	 m=0;
	 odd=even=0;
	for(int i=0;i<27;i++)
	{
		if(low[i]>m)m=low[i];
		if(high[i]>m)m=high[i];
		if(low[i]%2==0)even=1;
		else odd=1;
		if(high[i]%2==0)even=1;
		else odd=1;
	}
		if((m+n)>len)
	{
		if((n-len)%2==0)
		{
			if(even==1)
			a3=len;
			else
			a3=len-1;
		}
		else
		{
			if(odd=1)
			a3=len;
			a3=len-1;
		}
	}
	else
	a3=min(m+n,len);
	if(a1>a2&&a1>a3)
	cout<<"Kuro";
	else if(a2>a1&&a2>a3)
	cout<<"Shiro";
	else if(a3>a2&&a3>a1)
	cout<<"Katie";
	else
	cout<<"Draw";
	return 0;
}


