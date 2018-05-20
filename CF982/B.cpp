#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	IOS
    int n,m,l;
	
	priority_queue<pair<int,int> >intro;
	priority_queue<pair<int,int> >extro;
    
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		intro.push(make_pair((-1)*m,i));
	}	
	string s;
	cin>>s;
	l=2*n;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0')
		{
	     	pair<int,int> it=intro.top();
			intro.pop();
			cout<<it.second<<" ";
			extro.push(make_pair(it.first *(-1),it.second));
		}
		else
		{
			pair<int,int> it=extro.top();
			extro.pop();
			cout<<it.second<<" ";
		
		}
	}
	return 0;
}
