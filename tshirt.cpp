#include<bits/stdc++.h>
using namespace std;

long long getWays(vector<vector<int> > graph, vector<vector<int> > dp, long long mask, long long fullmask, long long i){
	
	if(mask==fullmask)
		return 1;

	if(i>100)
		return 0;

	if(dp[mask][i]!=-1)
		return dp[mask][i];

	long long ways = getWays(graph, dp, mask, fullmask, i+1);

	int persons_with_ith_tshirt=graph[i].size();

	for(int k=0; k < persons_with_ith_tshirt; k++){
		if(mask & (1<<graph[i][k])) 
			continue;

		ways=(ways + getWays(graph, dp, mask | (1<<graph[i][k]), fullmask, i+1)) % 1000000007;
	}

	return dp[mask][i]=ways;
}

int main(){
	
	vector<vector<int> > dp(1025, vector<int>(101,-1));
	vector<vector<int> > graph;
	
	int t;
	cin>>t;
	
	while(t--){
		int n, x;
		cin>>n;
		
		graph.clear();
		graph.resize(101);

		for(auto elem : dp)
			std::fill(elem.begin(), elem.end(), -1);

		long long mask=0, fullmask=(1<<n)-1;
		string s, t;
		
		getline(cin,s);
		for(int i=0;i<n;i++){
			getline(cin, s);
			stringstream st(s);
			while(st>>t){
				stringstream str(t);
				str>>x;
				graph[x].push_back(i);
			}
		}

		cout<<getWays(graph, dp, mask, fullmask, 1LL);

	}
}