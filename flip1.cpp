#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define N 105
int n,e,pay[N],cost[N],dp[N][2];
int solve(int p,int s)
{
	if(p==n)
	return 0;
	if(dp[p][s]!=-1)
	return dp[p][s];
	if(s==0)
	dp[p][s]=max(solve(p+1,0),pay[p]*e+solve(p,1));
	else
	dp[p][s]=max(solve(p+1,1),(-cost[p])*e+solve(p+1,0));
	return dp[p][s];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	dp[i][0]=dp[i][1]=-1;
	for(int i=0;i<n;i++)
	cin>>pay[i];
	for(int i=0;i<n;i++)
	cin>>cost[i];
	cin>>e;
	cout<<solve(0,0);
	return 0;
}
