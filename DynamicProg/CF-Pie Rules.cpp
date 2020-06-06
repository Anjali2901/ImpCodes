//859C : https://codeforces.com/problemset/problem/859/C
// Recursive method 
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define N 55
int n,a[N];
int pies(int idx,int chance)
{
	//function to optimize Bob's no of slices since he is the 1st player
	//chance 0 denotes Bob and chance 1 denotes Alice
    if(idx==n)
        return 0; 
    // if bob is the current player means he has the decider token
    //he can either keep decider token and let alice play
    int ans; 
    if(chance == 0)
    { 
        //a[idx]+pies(idx+1,1) - here he gives decider token to alice 
        //pies(idx+1,0) - here he won't eat and keep decider token with him
        ans = max(a[idx]+pies(idx+1,1),pies(idx+1,0));
    } 
    else 
    {
        //alice has the decider token now but we are optimizing bob's slices
        //pies(idx+1,1)+a[idx] - here alice will keep decider token and not eat,so bob will eat
        //  pies(idx+1,0) - "here alice eats" and gives decider token to bob 
        ans = min(a[idx]+pies(idx+1,1), pies(idx+1,0));
    }

    return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int bob=pies(0,0);
	cout<<sum-bob<<" "<<bob;
	return 0;
}

_____________________________________________________________________________________

// Top down dynamic programming

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define N 55
int n,a[N],dp[N][2];
//dp[i][0] will denotes bob's optimal share if he starts eating at ith index and Bob's chance 
//and dp[i][1] will denote Bob's optimal share  if he starts eating at ith index 
//and Alice's chance
//this is how top down dp differs from bottom up 
int pies(int idx,int chance)
{
	//function to optimize Bob's no of slices since he is the 1st player
	//chance 0 denotes Bob and chance 1 denotes Alice
    if(idx==n)
        return 0; 
    if(dp[idx][chance]!=-1)
        return dp[idx][chance];
    // if bob is the current player means he has the decider token
    //he can either keep decider token and let alice play
    int ans;  
    if(chance == 0)
    { 
        ans = max(a[idx]+pies(idx+1,1),pies(idx+1,0));
    } 
    else 
    {
        ans = min(a[idx]+pies(idx+1,1), pies(idx+1,0));
    }
    dp[idx][chance]=ans;
    return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		dp[i][0]=dp[i][1]=-1;
	}
	int bob=pies(0,0);
	cout<<sum-bob<<" "<<bob;
	return 0;
}
