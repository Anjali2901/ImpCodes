http://codeforces.com/contest/979/problem/A

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
	ll n,ans;
	cin>>n;
	if(n==0)
	ans=0;
	else if(n%2 == 0)
	ans=n+1;
	else 
	ans=(n+1)/2;
	cout<<ans;
	
}
