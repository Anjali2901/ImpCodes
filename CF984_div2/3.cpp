//By Anjali_2901, contest: Codeforces Round #483 (Div. 2) [Thanks, Botan Investments and Victor Shaburov!], problem: (C) Finite or not?, Accepted, #
//http://codeforces.com/contest/984/problem/C

#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<string>
#include<map>
#include<set>

#define ll long long
#define getD(n) scanf("%d",&n);//for input
#define getOL(n) scanf("%lld",&n);
#define getTL(n,m) scanf("%lld%lld",&n,&m);
#define getThL(n,m,r) scanf("%lld%lld%lld",&n,&m,&r);
#define outD(n) printf("%d",n);//for output
#define outL(n) printf("%lld",n);

#define nl printf("\n");//for new line
#define pb push_back 
#define mp make_pair

ll gcd(ll a,ll b)
{
	if(a%b==0)return b;
	if(b%a==0)return a;
	return gcd(b,a%b);
}
int main()
{

int t;
getD(t);
while(t--)
{
   ll p,q,b,r,g;
    getThL(p,q,b);
    if(p==0){
    	printf("Finite");
    	nl;
    	continue;
	}
	else{
	r=gcd(p,q);
	g=gcd(q,b);
	q/=r;
	while(g!=1)
	{
	   while(q%g == 0) q/=g;
	   g=gcd(q,b);	
	}
	if(q==1)
	  printf("Finite");
	else 
	  printf("Infinite");
	nl;  
   }
  }
}
