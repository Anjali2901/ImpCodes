//EZDIJKST

#include <bits/stdc++.h>
using namespace std;
 
const int INF = 2147483647;
const int MAX = 1e6+5;
int D[MAX], N; // Keeps minimum distance to each node
vector<pair<int,int> > E[MAX]; // Adjacency list
 
void dijkstra()
{
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push({0,1});
 
    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();
 
        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;
       vector<pair<int,int> > :: iterator pr;
        for(pr=E[u].begin();pr!=E[u].end();pr++)
        {
            int v = pr->first;
            int next_dist = dist + pr->second;
 
            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		while(m--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			E[a].push_back({c,b});
			E[b].push_back({c,a});
		}
		dijkstra();
		if(D[n]==INF)cout<<"NO\n";
		else cout<<D[n]<<"\n";
	}
}
