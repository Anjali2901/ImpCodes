//this code used Matrix exponentiation and f(1)+f(2)+f(3)+... + f(n) = f(n+2)-1 
/************************************my code **********************************************\
#include <iostream>
using namespace std;
#define mod 1000000007
#define ll long long
void matrix_power(ll A[][2],ll x)
{
     ll res[2][2]={{1,0},{0,1}};
     while( x > 0 )
     {
   	if(x%2==1)
   	{
   	   //res =  matrix_multiplication(res,A);
   	   ll sr,ij,h,rr;
   	   sr=res[0][0],ij=res[0][1],h=res[1][0],rr=res[1][1];
   	   res[0][0] = ((sr*A[0][0])%mod + (ij*A[1][0])%mod)%mod;
   	   res[0][1] = ((sr*A[0][1])%mod + (ij*A[1][1])%mod)%mod;  
   	   res[1][0] = ((h*A[0][0])%mod + (rr*A[1][0])%mod)%mod; 
   	   res[1][1] = ((h*A[0][1])%mod + (rr*A[1][1])%mod)%mod;
   	}
   	ll p,q,r,s;
	p = A[0][0],q=A[0][1],r=A[1][0],s=A[1][1];
	A[0][0] = ((p*p)%mod+(q*r)%mod)%mod;
	A[0][1] = ((p*q)%mod+(q*s)%mod)%mod;
	A[1][0] = ((r*p)%mod+(s*r)%mod)%mod;
	A[1][1] = ((r*q)%mod+(s*s)%mod)%mod;
	
	x = x/2;
     }
     A[0][0] = res[0][0];
     A[0][1] = res[0][1];
     A[1][0] = res[1][0];
     A[1][1] = res[1][1];
}
ll fib_expo(ll n)
{
  ll A[2][2] = {{0,1},{1,1}};
  if(n<=1)
    return n;
  matrix_power(A,n-1);
  ll res = (A[0][0]+A[0][1])%mod;
  return res;
}
int main()
{
     ll t,n,m,r1,r2;
     cin>>t;
     while(t--)
     {
       cin>>n>>m;
       r1 = fib_expo(n+1);
       r2 = fib_expo(m+2);
       cout<<(r2-r1+mod)%mod<<"\n";  
     }
}


/**************************************Little modified code below****************************************\
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
ll z=1000000007;
void multiply(ll f[][2],ll m[][2])
{
	ll x1= ((f[0][0]*m[0][0])%z + (f[0][1]*m[1][0])%z)%z;
	ll x2= ((f[0][0]*m[0][1])%z + (f[0][1]*m[1][1])%z)%z;
	ll x3= ((f[1][0]*m[0][0])%z + (f[1][1]*m[1][0])%z)%z;
	ll x4= ((f[1][0]*m[0][1])%z + (f[1][1]*m[1][1])%z)%z;
	f[0][0]=x1;
	f[0][1]=x2;
	f[1][0]=x3;
	f[1][1]=x4;
}
ll fib(int n)
{
	ll res[2][2]={{1,0},{0,1}},m[2][2]={{0,1},{1,1}};
	while(n>0)
	{
		if(n%2==1)
		multiply(res,m);
		multiply(m,m);
		n/=2;
	}
	return (res[0][0]+res[1][0])%z;
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
		int m,n;
		cin>>n>>m;
		cout<<(fib(m+1)-fib(n)+z)%z<<"\n";
	}
	return 0;
}
