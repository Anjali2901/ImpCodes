Method 1 : 
	
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define N 205
int n,a[N];
//use this
int min1(int a,int b,int c)
{
    return min(a,min(b,c));
}
int BorW(int idx,int prevW,int prevB)
{
    if(idx==n)
    return 0;
    int ans;
    if(a[idx]>prevB && a[idx]<prevW)
    {
        //all three colors can be assigned
        ans=min1(BorW(idx+1,a[idx],prevB),BorW(idx+1,prevW,a[idx]),1+BorW(idx+1,prevW,prevB));
    }
    else if(a[idx]>prevB)
    {
        //it can't be assigned white
        ans = min(BorW(idx+1,prevW,a[idx]),1+BorW(idx+1,prevW,prevB));
    }
    else if(a[idx]<prevW)
    {
        //it can't be assigned black
        ans = min(BorW(idx+1,a[idx],prevB),1+BorW(idx+1,prevW,prevB));
    }
    else 
    {
        //it can't be assigned white or black (possible case is for equal numbers) there are many
        //possible cases lets say pW is 5 and pB is 7 the a[idx] could be 6
        ans = 1+BorW(idx+1,prevW,prevB);
    }
    return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		cin>>n;
		if(n==-1)
		break;
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<BorW(0,100000000,-1)<<"\n";
	}
	return 0;
}
__________________________________________________________________________________
Method 2 : improved recursion

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define N 205
int n,a[N];
//use this
int min1(int a,int b,int c)
{
    return min(a,min(b,c));
}
int BorW(int idx,int prevW,int prevB)
{
    // three states for dp as clear by the function call, ans depends on the these three values
    // the constraints for idx, prevW and prevB - 200 for index and 10^6 for prevB and prevW
    // so 200*1e6*1e6 dp array can 't be made
    //if we look closely 
    //except the first call prevW and prevB are values from array
    //so instead of storing the values we can just store the indices
    //now for the initial idx lets chng smthngs start from idx=2  a[0]=-1 and a[1] = 1e7
    // sizeof dp array now can be 200 * 200 * 200
    if(idx==n+2) 
    return 0;
    int ans;
    if(a[idx]>a[prevB] && a[idx]<a[prevW])
    {
        //all three colors can be assigned
        ans=min1(BorW(idx+1,idx,prevB),BorW(idx+1,prevW,idx),1+BorW(idx+1,prevW,prevB));
    }
    else if(a[idx]>a[prevB])
    {
        //it can't be assigned white
        ans = min(BorW(idx+1,prevW,idx),1+BorW(idx+1,prevW,prevB));
    }
    else if(a[idx]<a[prevW])
    {
        //it can't be assigned black
        ans = min(BorW(idx+1,idx,prevB),1+BorW(idx+1,prevW,prevB));
    }
    else 
    {
        //it can't be assigned white or black
        ans = 1+BorW(idx+1,prevW,prevB);
    }
    return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		cin>>n;
		if(n==-1)
		break;
		a[0]=-1;a[1]=1e7;
		for(int i=2;i<=n+1;i++)
		cin>>a[i];
		cout<<BorW(2,1,0)<<"\n";
	}
	return 0;
}

__________________________________________________________
Method 3 : DP 

