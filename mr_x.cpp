// Mr. X
// Solution by Jacob Plachta

#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

int Eval(int v1,char o,int v2)
{
		if (o=='|')
			return(v1|v2);
		if (o=='&')
			return(v1&v2);
	return(v1^v2);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	// vars
	int T,t;
	int i,x,ss;
	char S[303],st[303];
	char res[2];
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			scanf("%s",&S);
			// evaluate expression for x=0 and x=1
				Fox(x,2)
				{
					ss=0;
						Fox(i,strlen(S))
							if (S[i]==')')
							{
								ss-=3;
								st[ss-1]=Eval(st[ss]-'0',st[ss+1],st[ss+2]-'0')+'0';
							}
							else
							if (S[i]=='x')
								st[ss++]=x+'0';
							else
							if (S[i]=='X')
								st[ss++]=(1-x)+'0';
							else
								st[ss++]=S[i];
					res[x]=st[0];
				}
			// output
			printf("Case #%d: %d\n",t,(res[0]==res[1])?0:1);
		}
	return(0);
}