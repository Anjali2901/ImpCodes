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
		cout<<BorW(0,-1,100000000)<<"\n";
	}
	return 0;
}
