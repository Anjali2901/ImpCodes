#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int N = 1e6+5;
map<ll,ll> vis;
map<pair<ll,ll>, ll > s;
ll ans=0ll;
int main()
{
	IOS
	ll n,a,b;
	cin>>n>>a>>b;
	ll x,vx,vy,r[n];
	
	for(ll i=0;i<n;i++)
	{
		cin>>x>>vx>>vy;
		r[i]=(a*vx)-vy;
		ans+=vis[a*vx-vy] - s[{vx,vy}];
			vis[r[i]]++;
	     	s[{vx,vy}]++;
	}
	
	cout<<2*ans<<"\n";
	
}
