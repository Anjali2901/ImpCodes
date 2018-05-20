#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
const int N=1e6+5;

 pair<ll,ll> p[N];
int main()
{
	IOS;
	ll n,l;
	cin>>n;
	l=2*n;
	ll a[n+1];   
	string s;
	for(ll i=1;i<=n;i++){
	  cin>>p[i].first;
	  p[i].second=i;
    }
    sort(p+1,p+n+1);
	cin>>s;
	ll ind=1;
	stack<ll> st;
	for(ll i=0;i<l;i++)
	{
		if(s[i]=='0')
		{
			cout<<p[ind].second<<" ";
			st.push(p[ind].second);
			ind++;
		}
		else
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	}
}
