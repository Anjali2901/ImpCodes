// Trees as a Service
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

#define MAXN 60
#define MAXM 120

int N,M;
int X[MAXM],Y[MAXM],Z[MAXM],P[MAXN];

bool BuildTree(int par,vector<int> nodes)
{
	int s=Sz(nodes);
	int i,j,k,a,b,c;
	bool here[MAXN]={0};
	bool good;
		Fox(i,s)
			here[nodes[i]]=1;
	// consider each possible root
		Fox(i,s)
		{
			// compute nodes which must or must not be in the same subtree
			int r=nodes[i];
			vector<int> con[MAXN];
			set<PR> badp;
			vector<vector<int> > subtrees;
			bool used[MAXN]={0};
				Fox(j,M)
					if (here[a=X[j]] && here[b=Y[j]] && here[c=Z[j]])
						if (a==r || b==r)
						{
							// LCA of pair including root must be equal to root
							if (c!=r)
								goto Bad;
						}
						else
						if (c==r)
						{
							// pair with LCA equal to root must be in different subtrees
							badp.insert(mp(a,b));
							badp.insert(mp(b,a));
						}
						else
						{
							// otherwise, triple must be in the same subtree
							con[a].pb(b);
							con[b].pb(a);
							con[a].pb(c);
							con[c].pb(a);
						}
			// floodfill to compute subtrees
				Fox(j,s)
					if (j!=i && !used[k=nodes[j]])
					{
						vector<int> subtree;
						queue<int> Q;
						Q.push(k),used[k]=1;
							while (!Q.empty())
							{
								k=Q.front(),Q.pop();
								subtree.pb(k);
									Fox(a,Sz(con[k]))
										if (!used[b=con[k][a]])
											Q.push(b),used[b]=1;
							}
							Fox(a,Sz(subtree))
								Fox(b,a)
									if (badp.count(mp(subtree[a],subtree[b])))
										goto Bad;
						subtrees.pb(subtree);
					}
			// recursively attempt to build each subtree
			P[r]=par;
				Fox(j,Sz(subtrees))
					if (!BuildTree(r,subtrees[j]))
						return(0);
			return(1);
Bad:;
		}
	return(0);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	// vars
	int T,t;
	int i;
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			Read(N),Read(M);
				Fox(i,M)
					Read(X[i]),Read(Y[i]),Read(Z[i]),X[i]--,Y[i]--,Z[i]--;
			// recursively build tree, and output
			Fill(P,-1);
			vector<int> nodes;
				Fox(i,N)
					nodes.pb(i);
			printf("Case #%d: ",t);
				if (!BuildTree(-1,nodes))
					printf("Impossible\n");
				else
				{
					Fox(i,N)
						printf("%d%c",P[i]+1,(i==N-1)?'\n':' ');
				}
		}
	return(0);
}