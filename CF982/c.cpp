#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
const int N=1e6+5;
int res=0;
pair<ll,ll> p[N];
vector<int> v[N];
bool vis[N];
int cnt[N]={0};

void dfs(int r)
{
	 vis[r]=true;
	 cnt[r]=1;
	 for(int i=0;i<v[r].size();i++)
	 {
	         if(vis[v[r][i]]) 
			     continue;
			  dfs(v[r][i]);			   
	    	cnt[r]+=cnt[v[r][i]];
			if(cnt[v[r][i]] % 2 == 0)res++;	 
	 }	 
}
//int check(int r)
//{
//	vis[r]=true;
//	for(int i=0;i<v[r].size();i++)
//	 {
//	   if(!vis[v[r][i]]){
//	      if(cnt[v[r][i]] % 2 == 0) res++;
//		  check(v[r][i]);  
//	 }	
//}
//int dfs(int ch,int par)
//{
//	int ct=1;
//	for(int i=0;i<v[ch].size();i++)
//	{
//		if(v[ch][i]!=par)
//		    ct+=dfs(v[ch][i],ch);
//	}
//	
//	if(par!=-1){
//		if(ct%2 == 0)res++;
//	}
//	return ct;
//}
int main()
{
	IOS;
	ll n,tmp,a,b;
	cin>>n;
	tmp=n-1;
	memset(vis,false,sizeof(vis));
	pair<int,int> p[n+1];
    for(int i=0;i<tmp;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		p[i]=make_pair(a,b); 
	}
    dfs(1);	
    
    if(n%2!=0)
	{
	  cout<<"-1";	
	}	
   	else
   	{
	      //dfs(1,-1);
	 // check(1);
 	  cout<<res;
	}
}
