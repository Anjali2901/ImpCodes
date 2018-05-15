#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,ans;
	cin>>n;
	vector<ll> v;
	vector<ll> :: iterator it;
	for(ll i=0;i<n;i++)
    {
    	cin>>m;
    	v.push_back(m);    	
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;i++)
	{
		if(i%2==0)
		 v.pop_back();
		else
		{
		  v.erase(v.begin());
		}
	}
	for(it=v.begin();it!=v.end();it++)
	{
		cout<<(*it);
	}
}
