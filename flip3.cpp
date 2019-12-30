#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int dp[1005][1005];
void pre(int n,int k)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		dp[i][j]=-1;
	}
}
int knap(int idx,int k,vector<int> &a)
{
	if(k==0)
	return 0;
	if(k<0 || idx<0)
	return 10000000;
	if(dp[idx][k]!=-1)
	return dp[idx][k];
	dp[idx][k]=min(knap(idx-1,k,a),1+knap(idx-1,k-a[idx],a));
	return dp[idx][k];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	pre(n,k);
	vector<int>a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	int ans=knap(n-1,k,a);
	if(ans>=10000000)
	cout<<-1;
	else
	cout<<ans;
	return 0;
}
