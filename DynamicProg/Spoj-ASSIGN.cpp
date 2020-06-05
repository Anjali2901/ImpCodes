Method - 1 : Recursion
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define D cout<<"1\n"
#define N (1<<20)
int a[20][20],n;
ll assign(int idx,int mask)
{
	//idx to denote the current student for which the assignment will be assigned
	//mask for indicating which assignments are already taken 
	//if kth bit is 1 in mask then kth assignment is taken else not 
	if(idx==n)
	{
	    return 1;
	}
	ll ways=0;
	for(int i=0;i<n;i++)
	{
	    //checing for all assignments 
	    int check=mask & (1<<i); //to check if ith bit is 1
	    if(check==0 && a[idx][i]==1) 
	    {
	        //ith bit is 0 
	        //ith assignment is not taken
	        //we can or can't assign this assignment to the student with index idx
	        //we will count the no of ways if this assignment is assigned to this student
	        ways+=assign(idx+1,mask | (1<<i)); // setting the ith bit of the mask to 1 
 	        //representing the assignment is assigned to this student 
	    }
	}
	//it is also possible that the function can not find a valid assignment which can be assigned to this student
	//we have to check if that assignment is favoured by the student or not 
	//if a[i][j] is 1 
	return ways;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cin>>a[i][j];
		}
		cout<<assign(0,0)<<"\n";
	}
	return 0;
}_________________________________________________________________________________
Method - 2 : DP (Top down)

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define D cout<<"1\n"
#define N (1<<20)
int a[20][20],n;
ll dp[25][N];
ll assign(int idx,int mask)
{
	//idx to denote the current student for which the assignment will be assigned
	//mask for indicating which assignments are already taken 
	//if kth bit is 1 in mask then kth assignment is taken else not 
	
	
	//two states are required idx and mask
	//constraints on idx is 20 , mask 1<<20
	// 20 bits for 20 assignments 
	//(1<<20) = 1048576 equivalent to 1e6 
	if(idx==n)
	{
	    return 1;
	}
	if(dp[idx][mask]!=-1)
	{
	    return dp[idx][mask];
	}
	ll ways=0;
	for(int i=0;i<n;i++)
	{
	    //checking for all assignments 
	    int check=mask & (1<<i); //to check if ith bit is 1
	    if(check==0 && a[idx][i]==1) 
	    {
	        //ith bit is 0 
	        //ith assignment is not taken
	        //we can or can't assign this assignment to the student with index idx
	        //we will count the no of ways if this assignment is assigned to this student
	        ways+=assign(idx+1,mask | (1<<i)); // setting the ith bit of the mask to 1 
 	        //representing the assignment is assigned to this student 
	    }
	}
	dp[idx][mask] = ways;
	//it is also possible that the function can not find a valid assignment which can be assigned to this student
	return ways; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cin>>a[i][j];
		}
		for(int i=0;i<20;i++)
		{
		    for(int j=0;j<N;j++)
		    {
		        dp[i][j]=-1;
		    }
		}
		cout<<assign(0,0)<<"\n";
	}
	return 0;
}
